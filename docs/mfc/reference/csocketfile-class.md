---
title: Classe CSocketFile
ms.date: 11/04/2016
f1_keywords:
- CSocketFile
- AFXSOCK/CSocketFile
- AFXSOCK/CSocketFile::CSocketFile
helpviewer_keywords:
- CSocketFile [MFC], CSocketFile
ms.assetid: 7924c098-5f72-40d6-989d-42800a47958f
ms.openlocfilehash: 3b969f81c0c6e1868a66aeaa1c4d9339792062df
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502458"
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

Você pode anexar o `CSocketFile` objeto a um `CSocket` objeto para essa finalidade. Você também pode, e geralmente, anexar o objeto `CSocketFile` a um objeto `CArchive` para simplificar o envio e o recebimento de dados usando a serialização do MFC.

Para serializar (enviar) dados, você o insere no arquivo morto, que `CSocketFile` chama funções de membro para gravar dados `CSocket` no objeto. Para desserializar (receber) dados, você extrai do arquivo morto. Isso faz com que o arquivo `CSocketFile` morto chame funções de membro para ler `CSocket` dados do objeto.

> [!TIP]
>  Além de `CSocketFile` usar conforme descrito aqui, você pode usá-lo como um objeto de arquivo autônomo, assim como é possível `CFile`com sua classe base. Você também pode usar `CSocketFile` o com qualquer função de serialização MFC baseada em arquivo. Como `CSocketFile` o não oferece suporte a `CFile`todas as funcionalidades do, algumas funções padrão serializadas do MFC `CSocketFile`não são compatíveis com o. Isso é especialmente verdadeiro para a `CEditView` classe. Você não deve tentar serializar `CEditView` dados por meio `CArchive` de um objeto anexado `CSocketFile` a um `CEditView::SerializeRaw`objeto usando `CEditView::Serialize` ; use em vez disso. A `SerializeRaw` função espera que o objeto de arquivo tenha funções, `Seek`como, que `CSocketFile` não têm.

Quando você usa `CArchive` o `CSocketFile` com `CSocket`o e o, pode encontrar uma `CSocket::Receive` situação em que o insere `PumpMessages(FD_READ)`um loop (por) aguardando a quantidade solicitada de bytes. Isso ocorre porque os soquetes do Windows permitem apenas uma chamada de recv por `CSocketFile` notificação `CSocket` de FD_READ, mas e permitem várias chamadas de recv por FD_READ. Se você receber um FD_READ quando não houver dados a serem lidos, o aplicativo será interrompido. Se você nunca obtiver outro FD_READ, o aplicativo deixará de se comunicar sobre o soquete.

Você pode resolver esse problema da seguinte maneira. No método da sua classe Socket, chame `CAsyncSocket::IOCtl(FIONREAD, ...)` antes de chamar o `Serialize` método da sua classe Message quando os dados esperados a serem lidos do soquete excederem o tamanho de um pacote TCP (unidade de transmissão máxima da mídia de rede `OnReceive` , geralmente pelo menos 1096 bytes). Se o tamanho dos dados disponíveis for menor que o necessário, aguarde até que todos os dados sejam recebidos e, em seguida, inicie a operação de leitura.

No exemplo a seguir, `m_dwExpected` é o número aproximado de bytes que o usuário espera receber. Supõe-se que você o declare em outro lugar em seu código.

[!code-cpp[NVC_MFCSocketThread#4](../../mfc/reference/codesnippet/cpp/csocketfile-class_1.cpp)]

Para obter mais informações, consulte [Windows Sockets in MFC](../../mfc/windows-sockets-in-mfc.md), [Windows Sockets: Usando soquetes com](../../mfc/windows-sockets-using-sockets-with-archives.md)arquivos mortos, bem como a [API do Windows Sockets 2](/windows/win32/WinSock/windows-sockets-start-page-2).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

`CSocketFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AfxSock. h

##  <a name="csocketfile"></a>  CSocketFile::CSocketFile

Constrói um objeto `CSocketFile`.

```
explicit CSocketFile(
    CSocket* pSocket,
    BOOL bArchiveCompatible = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pSocket*<br/>
O soquete a ser anexado ao `CSocketFile` objeto.

*bArchiveCompatible*<br/>
Especifica se o objeto de arquivo deve ser usado com `CArchive` um objeto. Passe false somente se você quiser usar o `CSocketFile` objeto de maneira autônoma como faria com um `CFile` objeto autônomo, com certas limitações. Esse sinalizador altera como o `CArchive` objeto anexado `CSocketFile` ao objeto gerencia seu buffer para leitura.

### <a name="remarks"></a>Comentários

O destruidor do objeto se desassocia do objeto Socket quando o objeto sai do escopo ou é excluído.

> [!NOTE]
>  Um `CSocketFile` também pode ser usado como um arquivo (limitado) sem um `CArchive` objeto. Por padrão, o `CSocketFile` parâmetro *bArchiveCompatible* do construtor é true. Isso especifica que o objeto de arquivo é para uso com um arquivo morto. Para usar o objeto File sem um arquivo morto, passe FALSE no parâmetro *bArchiveCompatible* .

Em seu modo "compatível com arquivo", `CSocketFile` um objeto fornece melhor desempenho e reduz o perigo de um "deadlock". Um deadlock ocorre quando os soquetes de envio e de recebimento estão aguardando um do outro, ou para um recurso comum. Essa situação pode ocorrer se o `CArchive` objeto funcionou `CSocketFile` com o modo como faz com um `CFile` objeto. Com `CFile`o, o arquivo pode assumir que, se receber menos bytes do que o solicitado, o final do arquivo foi atingido.

Com `CSocketFile`o, no entanto, os dados são baseados em mensagem; o buffer pode conter várias mensagens, portanto, o recebimento de menos do que o número de bytes solicitados não implica o fim do arquivo. O aplicativo não é bloqueado nesse caso como ele pode `CFile`, e pode continuar lendo mensagens do buffer até que o buffer esteja vazio. A função [CArchive:: IsBufferEmpty](../../mfc/reference/carchive-class.md#isbufferempty) é útil para monitorar o estado do buffer do arquivo nesse caso.

Para obter mais informações sobre o uso `CSocketFile`do, consulte os [artigos Windows Sockets: Usando soquetes com](../../mfc/windows-sockets-using-sockets-with-archives.md) arquivos [e Windows Sockets: Exemplo de soquetes usando](../../mfc/windows-sockets-example-of-sockets-using-archives.md)arquivos mortos.

## <a name="see-also"></a>Consulte também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)
