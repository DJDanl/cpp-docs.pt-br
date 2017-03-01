---
title: Estrutura WSADATA | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- WSADATA
dev_langs:
- C++
helpviewer_keywords:
- WSADATA structure
ms.assetid: 80cc60e5-f9ae-4290-8ed5-07003136627d
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 221e83f6bc926bbe632cdb1255898b91c257a1c9
ms.lasthandoff: 02/25/2017

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
 A versão da especificação do Windows Sockets que a DLL do Windows Sockets espera que o chamador para use.  
  
 *wHighVersion*  
 A versão mais recente da especificação do Windows Sockets que pode oferecer suporte a essa DLL (também codificada como acima). Normalmente, isso é o mesmo que **wVersion**.  
  
 *szDescription*  
 Uma cadeia de ASCII finalizados com null em que a DLL do Windows Sockets copia uma descrição da implementação do Windows Sockets, incluindo a identificação do fornecedor. O texto (até 256 caracteres) pode conter qualquer caractere, mas fornecedores são evitaram contra incluindo controle e formatação de caracteres: o uso mais provável que um aplicativo irá colocar isso é para exibi-lo (possivelmente truncado) em uma mensagem de status.  
  
 *szSystemStatus*  
 Uma cadeia de ASCII finalizados com null em que a DLL do Windows Sockets copia informações relevantes de status ou de configuração. A DLL do Windows Sockets deve usar este campo somente se as informações podem ser úteis para o usuário ou oferecer suporte à equipe; ele não deve ser considerado como uma extensão do **szDescription** campo.  
  
 *iMaxSockets*  
 O número máximo de soquetes que um único processo potencialmente pode abrir. Uma implementação do Windows Sockets pode fornecer um pool global de soquetes para alocação de qualquer processo. Como alternativa, ele pode alocar recursos por processo de soquetes. O número também pode refletir a maneira que a DLL do Windows Sockets ou o software de rede foi configurado. Criadores de aplicativo podem usar esse número como uma indicação crua se a implementação do Windows Sockets é usada pelo aplicativo. Por exemplo, um servidor X Windows pode verificar **iMaxSockets** quando iniciado pela primeira vez: se for menor do que 8, o aplicativo exibirá uma mensagem de erro instruindo o usuário para reconfigurar o software de rede. (Essa é uma situação na qual o **szSystemStatus** texto pode ser usado.) Obviamente, não há nenhuma garantia de que um determinado aplicativo pode alocar realmente **iMaxSockets** soquetes, já que pode haver outros aplicativos do Windows Sockets em uso.  
  
 *iMaxUdpDg*  
 O tamanho em bytes do maior datagrama de protocolo de datagrama de usuário (UDP) que podem ser enviadas ou recebidas por um aplicativo do Windows Sockets. Se a implementação não impõe limites, **iMaxUdpDg** é zero. Em muitas implementações de soquetes Berkeley, há um limite implícito de 8192 bytes datagramas UDP (que estão fragmentadas se necessário). Uma implementação do Windows Sockets pode impor um limite com base, por exemplo, na alocação de buffers de remontagem de fragmento. O valor mínimo de **iMaxUdpDg** para uma compatível com Windows Sockets implementação é 512. Observe que, independentemente do valor **iMaxUdpDg**, não é recomendável tentar enviar um datagrama de difusão é maior do que unidade máxima de transmissão (MTU) para a rede. (A API do Windows Sockets não fornecem um mecanismo para descobrir a MTU, mas deve ser nem menos de 512 bytes).  
  
 *lpVendorInfo*  
 Um ponteiro oposto a uma estrutura de dados específicos de fornecedor. A definição dessa estrutura (se fornecido) está além do escopo da especificação do Windows Sockets.  
  
> [!NOTE]
>  Em MFC, o `WSADATA` estrutura é retornada pelo `AfxSocketInit` função, que você chama em seu `InitInstance` função. Você pode recuperar a estrutura e armazená-lo em seu programa se você precisar usar informações dela mais tarde.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Winsock2  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [AfxSocketInit](../../mfc/reference/application-information-and-management.md#afxsocketinit)


