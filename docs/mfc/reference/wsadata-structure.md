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
ms.openlocfilehash: 93c98f792e1d72d3e6d4a8e15b8347c653b32f46
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33380078"
---
# <a name="wsadata-structure"></a>Estrutura WSADATA
O `WSADATA` estrutura é usada para armazenar informações de inicialização do Windows Sockets retornadas por uma chamada para o `AfxSocketInit` função global.  
  
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
 A versão da especificação do Windows Sockets que a DLL do Windows Sockets espera que o chamador para usar.  
  
 *wHighVersion*  
 A versão mais recente da especificação de Windows Sockets que pode dar suporte a esta DLL (também codificada como acima). Normalmente, isso é o mesmo que **wVersion**.  
  
 *szDescription*  
 Uma cadeia de ASCII terminada em nulo para o qual o DLL do Windows Sockets copia uma descrição da implementação do Windows Sockets, incluindo a identificação do fornecedor. O texto (até 256 caracteres) pode conter quaisquer caracteres, mas fornecedores são evitaram contra incluindo controle e formatação de caracteres: o uso mais provável que um aplicativo colocará isso para é para exibi-lo (possivelmente truncado) em uma mensagem de status.  
  
 *szSystemStatus*  
 Uma cadeia de ASCII terminada em nulo na qual o DLL do Windows Sockets copia informações relevantes de configuração ou status. A DLL do Windows Sockets deve usar este campo somente se as informações podem ser úteis para o usuário ou oferecer suporte à equipe; ele não deve ser considerado como uma extensão do **szDescription** campo.  
  
 *iMaxSockets*  
 O número máximo de soquetes que um único processo potencialmente pode abrir. Uma implementação do Windows Sockets pode fornecer um pool global de soquetes para alocação a qualquer processo; Como alternativa, ele pode alocar recursos por processo de soquetes. O número também pode refletir a maneira na qual o DLL do Windows Sockets ou o software de rede foi configurado. Gravadores de aplicativo podem usar esse número como uma indicação crua se a implementação do Windows Sockets é usada pelo aplicativo. Por exemplo, um servidor X Windows pode verificar **iMaxSockets** quando iniciado pela primeira vez: se for inferior a 8, o aplicativo exibirá uma mensagem de erro solicitando que o usuário para reconfigurar o software de rede. (Essa é uma situação na qual o **szSystemStatus** texto pode ser usado.) Obviamente, não há nenhuma garantia de que um aplicativo específico, na verdade, pode alocar **iMaxSockets** soquetes, já que pode haver outros aplicativos do Windows Sockets em uso.  
  
 *iMaxUdpDg*  
 O tamanho em bytes do maior datagrama de protocolo UDP (User Datagram) que podem ser enviadas ou recebidas por um aplicativo do Windows Sockets. Se a implementação não impõe limites, **iMaxUdpDg** é zero. Em muitas implementações de soquetes Berkeley, há um limite implícito de 8192 bytes datagramas UDP (que são fragmentadas se necessário). Uma implementação do Windows Sockets pode impor um limite com base, por exemplo, a alocação de buffers de remontagem de fragmento. O valor mínimo de **iMaxUdpDg** para um Windows Sockets compatível com a implementação é 512. Observe que, independentemente do valor de **iMaxUdpDg**, não é recomendável tentar enviar um datagrama de difusão é maior do que unidade máxima de transmissão (MTU) para a rede. (API do Windows Sockets não fornecem um mecanismo para descobrir a MTU, mas ele deve ser menor do que 512 bytes).  
  
 *lpVendorInfo*  
 Um ponteiro oposto a uma estrutura de dados específicos de fornecedor. A definição dessa estrutura (se fornecida) está além do escopo da especificação de Windows Sockets.  
  
> [!NOTE]
>  Em MFC, o `WSADATA` estrutura é retornada pelo `AfxSocketInit` função, que você chamar no seu `InitInstance` função. Você pode recuperar a estrutura e armazená-lo em seu programa, se você precisar usar informações-lo mais tarde.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Winsock2  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit)

