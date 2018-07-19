---
title: Estrutura WSADATA | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- WSADATA
dev_langs:
- C++
helpviewer_keywords:
- WSADATA structure [MFC]
ms.assetid: 80cc60e5-f9ae-4290-8ed5-07003136627d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dadc502900285d879f2fd77af69b1fcf08a4ba1e
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37880925"
---
# <a name="wsadata-structure"></a>Estrutura WSADATA
O `WSADATA` estrutura é usada para armazenar informações de inicialização de soquetes do Windows retornadas por uma chamada para o `AfxSocketInit` função global.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct WSAData {  
    WORD wVersion;  
    WORD wHighVersion;  
    char szDescription[WSADESCRIPTION_LEN+1];  
    char szSystemStatus[WSASYSSTATUS_LEN+1];  
    unsigned short iMaxSockets;  
    unsigned short iMaxUdpDg;  
    char FAR* lpVendorInfo;  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *wVersion*  
 A versão da especificação do Windows Sockets que a DLL de soquetes do Windows espera que o chamador use.  
  
 *wHighVersion*  
 A versão mais recente da especificação do Windows Sockets que pode dar suporte a essa DLL (também codificada como acima). Normalmente, isso é o mesmo que *wVersion*.  
  
 *szDescription*  
 Uma cadeia de ASCII terminada em nulo para a qual o Windows Sockets. DLL copia uma descrição da implementação do Windows Sockets, incluindo a identificação do fornecedor. O texto (até 256 caracteres de comprimento) pode conter quaisquer caracteres, mas os fornecedores estão evitaram contra incluindo controle e formatação de caracteres: o uso mais provável que um aplicativo colocará isso para é para exibi-lo (possivelmente truncado) em uma mensagem de status.  
  
 *szSystemStatus*  
 Uma cadeia de ASCII terminada em nulo para a qual o Windows Sockets. DLL copia informações relevantes de status ou de configuração. O Windows Sockets. DLL deve usar este campo somente se as informações podem ser úteis para o usuário ou equipe; de suporte ele não deve ser considerado como uma extensão dos *szDescription* campo.  
  
 *iMaxSockets*  
 O número máximo de soquetes que um único processo potencialmente pode ser abertos. Uma implementação de soquetes do Windows pode fornecer um pool global de soquetes para alocação a qualquer processo; Como alternativa, ele poderá alocar recursos por processo para soquetes. O número também pode refletir a maneira na qual o Windows Sockets. DLL ou o software de rede foi configurado. Criadores de aplicativo podem usar esse número como uma indicação crua de se a implementação do Windows Sockets está utilizável pelo aplicativo. Por exemplo, um servidor Windows X pode verificar *iMaxSockets* quando iniciado pela primeira vez: se for menor do que 8, o aplicativo exibirá uma mensagem de erro instruindo o usuário para reconfigurar o software de rede. (Essa é uma situação na qual o *szSystemStatus* texto pode ser usado.) Obviamente, não há nenhuma garantia de que um aplicativo específico, na verdade, pode alocar *iMaxSockets* soquetes, já que pode haver outros aplicativos do Windows Sockets em uso.  
  
 *iMaxUdpDg*  
 O tamanho em bytes do maior datagrama de protocolo UDP (User Datagram) que pode ser enviado ou recebido por um aplicativo do Windows Sockets. Se a implementação não impõe limites, *iMaxUdpDg* é zero. Em muitas implementações de soquetes Berkeley, há um limite implícito de 8.192 bytes em datagramas UDP (que estão fragmentadas se necessário). Uma implementação de soquetes do Windows pode impor um limite com base, por exemplo, na alocação de buffers de remontagem de fragmento. O valor mínimo do *iMaxUdpDg* para um soquetes do Windows compatíveis com a implementação é 512. Observe que, independentemente do valor *iMaxUdpDg*, não é recomendável tentar enviar um datagrama de difusão é maior do que de unidade de transmissão máxima (MTU) para a rede. (A API de soquetes do Windows não fornece um mecanismo para descobrir a MTU, mas ele deve ser menor do que 512 bytes).  
  
 *lpVendorInfo*  
 Um ponteiro distante a uma estrutura de dados específicos de fornecedor. A definição dessa estrutura (se fornecido) está além do escopo da especificação do Windows Sockets.  
  
> [!NOTE]
>  No MFC, o `WSADATA` retornada pela estrutura o `AfxSocketInit` função, que você chamar em seu `InitInstance` função. Você pode recuperar a estrutura e armazená-lo em seu programa, se você precisar usar informações dela mais tarde.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** winsock2.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit)

