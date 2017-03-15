---
title: Classe CSocketFile | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSocketFile
dev_langs:
- C++
helpviewer_keywords:
- networks [C++], archive
- serialization [C++], network
- networks [C++], serializing to
- CSocketFile class
- archives [C++], network
- SOCKET handle
ms.assetid: 7924c098-5f72-40d6-989d-42800a47958f
caps.latest.revision: 24
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 6ca331c07e0a9fc48f152042fcccd5c38e743ccf
ms.lasthandoff: 02/25/2017

---
# <a name="csocketfile-class"></a>Classe CSocketFile
Um `CFile` objeto usado para enviar e receber dados em uma rede por meio do Windows Sockets.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSocketFile : public CFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSocketFile::CSocketFile](#csocketfile)|Constrói um objeto `CSocketFile`.|  
  
## <a name="remarks"></a>Comentários  
 Você pode anexar o `CSocketFile` o objeto para um `CSocket` objeto para essa finalidade. Você também pode e, normalmente, anexar o `CSocketFile` do objeto para um `CArchive` objeto para simplificar o envio e recebimento de dados usando a serialização do MFC.  
  
 Para serializar os dados (Enviar), inseri-lo no arquivo morto, que chama `CSocketFile` funções de membro para gravar os dados para o `CSocket` objeto. Para desserializar (receber) dados, extrair do arquivo morto. Isso faz com que o arquivo morto para chamar `CSocketFile` funções de membro para ler dados a `CSocket` objeto.  
  
> [!TIP]
>  Além de usar `CSocketFile` conforme descrito aqui, você pode usá-lo como um objeto de arquivo autônomo, exatamente como faria com `CFile`, sua classe base. Você também pode usar `CSocketFile` com quaisquer funções de serialização do MFC com base em arquivo. Porque `CSocketFile` não suportar todos `CFile`da funcionalidade, alguns padrão MFC serializar funções não são compatíveis com `CSocketFile`. Isso é particularmente verdadeiro de `CEditView` classe. Você não deve tentar serializar `CEditView` dados por meio de um `CArchive` objeto anexado a um `CSocketFile` objeto usando `CEditView::SerializeRaw`; use **CEditView::Serialize** em vez disso. O `SerializeRaw` função espera que o objeto de arquivo com funções, como `Seek`, que `CSocketFile` não tem.  
  
 Quando você usa `CArchive` com `CSocketFile` e `CSocket`, você pode encontrar uma situação onde **CSocket::Receive** entra em um loop (por **PumpMessages(FD_READ)**) aguardando a quantidade de bytes solicitada. Isso ocorre porque o Windows sockets permite somente uma chamada de recebimento por notificação FD_READ, mas `CSocketFile` e `CSocket` permitir várias chamadas de recebimento por FD_READ. Se você receber um FD_READ quando não há nenhum dado a ser lido, o aplicativo trava. Se você nunca receber outra FD_READ, o aplicativo para se comunicar por soquete.  
  
 Você pode resolver esse problema, da seguinte maneira. No `OnReceive` método da classe do soquete, chamada **CAsyncSocket::IOCtl (FIONREAD...) ** antes de chamar o `Serialize` método de sua classe de mensagem quando os dados esperados para leitura a partir do soquete excedem o tamanho de um pacote TCP (unidade máxima de transmissão de mídia de rede geralmente pelo menos 1096 bytes). Se o tamanho dos dados disponíveis é menor que o necessário, aguarde todos os dados recebidos e apenas iniciar a operação de leitura.  
  
 No exemplo a seguir, `m_dwExpected` é o número aproximado de bytes que o usuário espera receber. Supõe-se que você declare-o em outro lugar no seu código.  
  
 [!code-cpp[NVC_MFCSocketThread n º&4;](../../mfc/reference/codesnippet/cpp/csocketfile-class_1.cpp)]  
  
 Para obter mais informações, consulte [Windows Sockets em MFC](../../mfc/windows-sockets-in-mfc.md), [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md), bem como [API do Windows Sockets 2](http://msdn.microsoft.com/library/windows/desktop/ms740673).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 `CSocketFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxsock.h  
  
##  <a name="a-namecsocketfilea--csocketfilecsocketfile"></a><a name="csocketfile"></a>CSocketFile::CSocketFile  
 Constrói um objeto `CSocketFile`.  
  
```  
explicit CSocketFile(
    CSocket* pSocket,  
    BOOL bArchiveCompatible = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSocket`  
 O soquete para anexar o `CSocketFile` objeto.  
  
 `bArchiveCompatible`  
 Especifica se o objeto de arquivo é para uso com um `CArchive` objeto. Passar **FALSE** somente se você quiser usar o `CSocketFile` como você faria autônomo do objeto de maneira autônoma `CFile` objeto, com certas limitações. Esse sinalizador é alterado como o `CArchive` objeto associado a `CSocketFile` objeto gerencia seu buffer de leitura.  
  
### <a name="remarks"></a>Comentários  
 O destruidor do objeto desassocia próprio do objeto de soquete quando o objeto sai do escopo ou é excluído.  
  
> [!NOTE]
>  A `CSocketFile` também pode ser usado como um arquivo (limitado) sem uma `CArchive` objeto. Por padrão, o `CSocketFile` do construtor `bArchiveCompatible` parâmetro é **TRUE**. Isso especifica que o objeto de arquivo é para uso com um arquivo morto. Para usar o objeto de arquivo sem um arquivo morto, passe **FALSE** no `bArchiveCompatible` parâmetro.  
  
 No modo de "arquivo morto compatível", um `CSocketFile` objeto oferece melhor desempenho e reduz o risco de "bloqueio". Um deadlock ocorre quando os soquetes de envio e recebimento estão esperando um do outro, ou para um recurso comum. Essa situação pode ocorrer se o `CArchive` objeto trabalhou com a `CSocketFile` da forma que faz com uma `CFile` objeto. Com `CFile`, o arquivo morto pode assumir que se ele recebe alguns dos bytes solicitada, o final do arquivo foi atingido.  
  
 Com `CSocketFile`, no entanto, dados forem baseado em mensagem; o buffer pode conter várias mensagens, então receber menos que o número de bytes solicitado não implica o final do arquivo. O aplicativo não bloqueia neste caso, como pode ocorrer com `CFile`, e pode continuar lendo mensagens do buffer até que o buffer está vazio. O [CArchive::IsBufferEmpty](../../mfc/reference/carchive-class.md#isbufferempty) função é útil para monitorar o estado do buffer do arquivo nesse caso.  
  
 Para obter mais informações sobre o uso de `CSocketFile`, consulte os artigos [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md) e [Windows Sockets: exemplo de soquetes usando arquivos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)   
 [Classe CSocket](../../mfc/reference/csocket-class.md)

