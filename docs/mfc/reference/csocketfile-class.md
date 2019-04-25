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
ms.openlocfilehash: f3fa73320ae34283b0cdac559111a53a879c031c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62324045"
---
# <a name="csocketfile-class"></a>Classe CSocketFile

Um `CFile` objeto usado para enviar e receber dados em uma rede por meio de soquetes do Windows.

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

Você pode anexar a `CSocketFile` do objeto para um `CSocket` objeto para essa finalidade. Você também pode e, geralmente, anexar a `CSocketFile` do objeto para um `CArchive` objeto para simplificar o envio e recebimento de dados usando a serialização do MFC.

Para serializar os dados (Enviar), você inseri-lo para o arquivamento, que chama `CSocketFile` funções de membro para gravar os dados para o `CSocket` objeto. Para desserializar (recebimento) dados, é extrair o arquivo morto. Isso faz com que o arquivo morto chamar `CSocketFile` funções de membro para ler dados do `CSocket` objeto.

> [!TIP]
>  Além de usar `CSocketFile` conforme descrito aqui, você pode usá-lo como um objeto de arquivo autônomo, exatamente como é possível com `CFile`, sua classe base. Você também pode usar `CSocketFile` com quaisquer funções de serialização do MFC com base em arquivo morto. Porque `CSocketFile` não dá suporte a todos os `CFile`da funcionalidade, algum padrão MFC serializar funções não são compatíveis com `CSocketFile`. Isso é particularmente verdadeiro o `CEditView` classe. Você não deve tentar serializar `CEditView` dados por meio de um `CArchive` objeto anexado a um `CSocketFile` objeto usando `CEditView::SerializeRaw`; usar `CEditView::Serialize` em vez disso. O `SerializeRaw` função espera que o objeto de arquivo ter funções, como `Seek`, que `CSocketFile` não tem.

Quando você usa `CArchive` com `CSocketFile` e `CSocket`, você pode encontrar uma situação em que `CSocket::Receive` entra em um loop (por `PumpMessages(FD_READ)`) aguardando a quantidade solicitada de bytes. Isso ocorre porque soquetes do Windows permitem que apenas uma chamada de recebimento por notificação FD_READ, mas `CSocketFile` e `CSocket` permitir várias chamadas de recebimento por FD_READ. Se você receber um FD_READ quando não há nenhum dado a ser lido, o aplicativo para de responder. Se você nunca receber outra FD_READ, o aplicativo para se comunicar por soquete.

Você pode resolver esse problema, da seguinte maneira. No `OnReceive` método de sua classe socket, chamada `CAsyncSocket::IOCtl(FIONREAD, ...)` antes de chamar o `Serialize` método de sua classe de mensagem quando os dados esperados sejam lidos a partir do soquete excedem o tamanho de um pacote TCP (unidade máxima de transmissão de mídia de rede Normalmente, pelo menos 1096 bytes). Se o tamanho dos dados disponíveis é menor que o necessário, aguarde a todos os dados a ser recebida e só então começa a operação de leitura.

No exemplo a seguir, `m_dwExpected` é o número aproximado de bytes que o usuário espera receber. Supõe-se que você declare-o em outro lugar no seu código.

[!code-cpp[NVC_MFCSocketThread#4](../../mfc/reference/codesnippet/cpp/csocketfile-class_1.cpp)]

Para obter mais informações, consulte [Windows Sockets em MFC](../../mfc/windows-sockets-in-mfc.md), [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md), bem como [API do Windows Sockets 2](/windows/desktop/WinSock/windows-sockets-start-page-2).

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

*pSocket*<br/>
O soquete para anexar o `CSocketFile` objeto.

*bArchiveCompatible*<br/>
Especifica se o objeto de arquivo é para uso com um `CArchive` objeto. Passe FALSE apenas se você quiser usar o `CSocketFile` do objeto de forma autônoma como você faria com um autônomo `CFile` objeto, com certas limitações. Esse sinalizador é alterado como o `CArchive` objeto anexado a `CSocketFile` objeto gerencia o buffer para leitura.

### <a name="remarks"></a>Comentários

O destruidor do objeto desassocia próprio do objeto de soquete quando o objeto sai do escopo ou é excluído.

> [!NOTE]
>  Um `CSocketFile` também pode ser usado como um arquivo (limitado) sem um `CArchive` objeto. Por padrão, o `CSocketFile` do construtor *bArchiveCompatible* parâmetro for TRUE. Isso especifica que o objeto de arquivo é para uso com um arquivo morto. Para usar o objeto de arquivo sem um arquivo morto, passe FALSE na *bArchiveCompatible* parâmetro.

No modo de "compatível com o arquivo morto", um `CSocketFile` objeto fornece um melhor desempenho e reduz o risco de um "deadlock". Um deadlock ocorre quando os soquetes de envio e recebimento estão esperando um pelo outro, ou para um recurso comum. Essa situação pode ocorrer se o `CArchive` objeto trabalhou com o `CSocketFile` da forma que faz com um `CFile` objeto. Com `CFile`, o arquivo morto pode presumir que se ela recebe menos bytes que ele é solicitado, o final do arquivo foi atingido.

Com `CSocketFile`, no entanto, dados for baseado em mensagem; o buffer pode conter várias mensagens, então receber menos do que o número de bytes solicitado não implica o final do arquivo. O aplicativo não bloqueia neste caso, como pode ocorrer com `CFile`, e pode continuar lendo mensagens do buffer até que o buffer está vazio. O [CArchive::IsBufferEmpty](../../mfc/reference/carchive-class.md#isbufferempty) função é útil para monitorar o estado do buffer do arquivo morto nesse caso.

Para obter mais informações sobre o uso de `CSocketFile`, consulte os artigos [Windows Sockets: Usando soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md) e [Windows Sockets: Exemplo de soquetes que usam arquivos mortos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).

## <a name="see-also"></a>Consulte também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)
