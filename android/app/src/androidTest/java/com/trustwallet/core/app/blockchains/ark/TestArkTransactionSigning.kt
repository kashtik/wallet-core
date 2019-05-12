package com.trustwallet.core.app.blockchains.ark

import com.google.gson.Gson
import com.google.gson.annotations.SerializedName
import com.google.protobuf.ByteString
import com.trustwallet.core.app.utils.toHexByteArray
import junit.framework.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.ARKSigner
import wallet.core.jni.proto.ARK

class TestArkTransactionSigning{
    init {
        System.loadLibrary("TrustWalletCore")
    }
    @Test
    fun arkTransactionSigning(){
        val signingInput = ARK.SigningInput.newBuilder()
            .setAmount(1000000000)
            .setPrivateKey(ByteString.copyFrom("0xd8839c2432bfd0a67ef10a804ba991eabba19f154a3d707917681d45822a5712"
                .toHexByteArray()))
            .setTimestamp(50686854)
            .setRecipientId("ANBkoGqWeTSiaEVgVzSKZd3jS7UWzv9PSo")
            .build()

        val output = ARKSigner.sign(signingInput)
        val arkTransaction = Gson().fromJson(output.json, ArkTransaction::class.java)

        assertEquals(arkTransaction.signature, "304402201ace9afcaf9d0ec64a31fd98c589767c76b5360d5b22dfe3cde2dfffdfef61dc022026d276a6140e6abbd80775541479cc71cf52590895bd24c0c577a9c57ecae581")
        assertEquals(arkTransaction.senderPublicKey, "034151a3ec46b5670a682b0a63394f863587d1bc97483b1b6c70eb58e7f0aed192")

    }

    data class ArkTransaction (
        @SerializedName("amount") val amount : Int,
        @SerializedName("asset") val asset : Asset,
        @SerializedName("fee") val fee : Int,
        @SerializedName("id") val id : String,
        @SerializedName("recipientId") val recipientId : String,
        @SerializedName("senderPublicKey") val senderPublicKey : String,
        @SerializedName("signature") val signature : String,
        @SerializedName("timestamp") val timestamp : Int,
        @SerializedName("type") val type : Int
    )

    class Asset
}