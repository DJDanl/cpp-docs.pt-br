---
title: Classe CSocketFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSocketFile
- AFXSOCK/CSocketFile
- AFXSOCK/CSocketFile::CSocketFile
dev_langs:
- C++
helpviewer_keywords:
- CSocketFile [MFC], CSocketFile
ms.assetid: 7924c098-5f72-40d6-989d-42800a47958f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4f1198c85b8366d7dec4d38d002b65468c38347c
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37121722"
---
# <a name="csocketfile-class"></a>Classe CSocketFile
Um `CFile` objeto usado para enviar e receber dados pela rede por meio do Windows Sockets.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSocketFile : public CFile  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSocketFile::CSocketFile](#csocketfile)|Constrói um objeto `CSocketFile`.|  
  
## <a name="remarks"></a>Comentários  
 Você pode anexar o `CSocketFile` o objeto para um `CSocket` objeto para essa finalidade. Você também pode e, geralmente, anexar o `CSocketFile` o objeto para um `CArchive` objeto para simplificar o envio e recebimento de dados usando a serialização do MFC.  
  
 Para serializar os dados (envio), insira-a no arquivo, que chama `CSocketFile` funções de membro para gravar os dados para o `CSocket` objeto. Desserializar (receber) dados extraídos do arquivo morto. Isso faz com que o arquivo para chamar `CSocketFile` funções de membro para ler dados a `CSocket` objeto.  
  
> [!TIP]
>  Além de usar `CSocketFile` conforme descrito aqui, você pode usá-lo como um objeto de arquivo autônomo, exatamente como faria com `CFile`, sua classe base. Você também pode usar `CSocketFile` com qualquer função de serialização do MFC com base em arquivo. Porque `CSocketFile` não dá suporte a todos os `CFile`da funcionalidade, alguns padrão MFC serializar funções não são compatíveis com `CSocketFile`. Isso é particularmente verdadeiro a `CEditView` classe. Você não deve tentar serializar `CEditView` dados por meio de um `CArchive` objeto anexado a um `CSocketFile` objeto usando `CEditView::SerializeRaw`; use `CEditView::Serialize` em vez disso. O `SerializeRaw` a função espera o objeto de arquivo com funções, como `Seek`, que `CSocketFile` não tem.  
  
 Quando você usa `CArchive` com `CSocketFile` e `CSocket`, você pode encontrar uma situação onde `CSocket::Receive` inserirá um loop (por `PumpMessages(FD_READ)`) aguardando a quantidade solicitada de bytes. Isso é porque o Windows sockets permite somente uma chamada de recebimento por notificação FD_READ, mas `CSocketFile` e `CSocket` permitir várias chamadas de recebimento por FD_READ. Se você receber um FD_READ quando não há nenhum dado a ser lido, o aplicativo continua. Se você nunca receber outra FD_READ, o aplicativo para se comunicar por soquete.  
  
 Você pode resolver esse problema, da seguinte maneira. No `OnReceive` método da classe do soquete, chamada `CAsyncSocket::IOCtl(FIONREAD, ...)` antes de chamar o `Serialize` método de sua classe de mensagem quando os dados esperados para ser lido do soquete excedem o tamanho de um pacote TCP (unidade máxima de transmissão de mídia de rede geralmente pelo menos 1096 bytes). Se o tamanho dos dados disponíveis é menor que o necessário, aguarde para todos os dados a ser recebida e só então iniciar a operação de leitura.  
  
 No exemplo a seguir, `m_dwExpected` é o número aproximado de bytes que o usuário espera receber. Presume-se que você declare-o em outro lugar no seu código.  
  
 [!code-cpp[NVC_MFCSocketThread#4](../../mfc/reference/codesnippet/cpp/csocketfile-class_1.cpp)]  
  
 Para obter mais informações, consulte [Windows Sockets em MFC](../../mfc/windows-sockets-in-mfc.md), [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md), bem como [API do Windows Sockets 2](http://msdn.microsoft.com/library/windows/desktop/ms740673).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 `CSocketFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxsock.h  
  
##  <a name="csocketfile"></a>  CSocketFile::CSocketFile  
 Constrói um objeto `CSocketFile`.  
  
```  
explicit CSocketFile(
    CSocket* pSocket,  
    BOOL bArchiveCompatible = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pSocket*  
 O soquete para anexar o `CSocketFile` objeto.  
  
 *bArchiveCompatible*  
 Especifica se o objeto de arquivo é para uso com um `CArchive` objeto. Passe FALSE apenas se você quiser usar o `CSocketFile` do objeto de forma independente como faria com um autônomo `CFile` objeto, com certas limitações. Esse sinalizador é alterado como o `CArchive` objeto associado a `CSocketFile` objeto gerencia seu buffer de leitura.  
  
### <a name="remarks"></a>Comentários  
 Destruidor do objeto desassocia próprio do objeto de soquete quando o objeto sai do escopo ou é excluído.  
  
> [!NOTE]
>  Um `CSocketFile` também pode ser usado como um arquivo (limitado) sem um `CArchive` objeto. Por padrão, o `CSocketFile` do construtor *bArchiveCompatible* parâmetro for TRUE. Isso especifica que o objeto de arquivo é para uso com um arquivo morto. Para usar o objeto de arquivo sem um arquivo morto, passe FALSE no *bArchiveCompatible* parâmetro.  
  
 No modo de "compatível com o arquivo", um `CSocketFile` objeto fornece um melhor desempenho e reduz o risco de um "bloqueio". Um deadlock ocorre quando os soquetes de envio e recebimento estão esperando um do outro, ou para um recurso comum. Esta situação pode ocorrer se o `CArchive` objeto trabalhou com o `CSocketFile` da forma que faz com um `CFile` objeto. Com `CFile`, o arquivo morto pode assumir que se ele recebe menos bytes solicitados por ele, o final do arquivo foi atingido.  
  
 Com `CSocketFile`, no entanto, dados for baseado em mensagem; o buffer pode conter várias mensagens, para receber menos do que o número de bytes solicitado não implica a fim de arquivo. O aplicativo não bloquear nesse caso, como pode ocorrer com `CFile`, e ele poderá continuar a ler mensagens do buffer até que o buffer está vazio. O [CArchive::IsBufferEmpty](../../mfc/reference/carchive-class.md#isbufferempty) função é útil para monitorar o estado de buffer do arquivo nesse caso.  
  
 Para obter mais informações sobre o uso de `CSocketFile`, consulte os artigos [Windows Sockets: usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md) e [Windows Sockets: exemplo de soquetes usando arquivos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CFile](../../mfc/reference/cfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)   
 [Classe CSocket](../../mfc/reference/csocket-class.md)
