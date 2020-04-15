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
ms.openlocfilehash: 83810a05925e5c8302240b61d95c131fdd78b426
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318171"
---
# <a name="csocketfile-class"></a>Classe CSocketFile

Um `CFile` objeto usado para enviar e receber dados através de uma rede via Soquetes do Windows.

## <a name="syntax"></a>Sintaxe

```
class CSocketFile : public CFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Arquivo de csocket::CSocketFile](#csocketfile)|Constrói um objeto `CSocketFile`.|

## <a name="remarks"></a>Comentários

Você pode `CSocketFile` anexar o `CSocket` objeto a um objeto para este fim. Você também pode, e geralmente `CSocketFile` faz, `CArchive` anexar o objeto a um objeto para simplificar o envio e o recebimento de dados usando serialização de MFC.

Para serializar (enviar) dados, insira-os `CSocketFile` no arquivo, que `CSocket` chama as funções do membro para gravar dados no objeto. Para desserializar (receber) dados, você extrai do arquivo. Isso faz com `CSocketFile` que o arquivo chame `CSocket` funções de membro para ler dados do objeto.

> [!TIP]
> Além `CSocketFile` de usar como descrito aqui, você pode usá-lo como `CFile`um objeto de arquivo autônomo, assim como você pode com , sua classe base. Você também `CSocketFile` pode usar com quaisquer funções de serialização MFC baseadas em arquivos. Como `CSocketFile` não suporta `CFile`todas as funcionalidades de ', algumas funções `CSocketFile`de serialização de MFC padrão não são compatíveis com . Isso é particularmente `CEditView` verdadeiro para a classe. Você não deve tentar `CEditView` serializar `CArchive` dados através `CSocketFile` de `CEditView::SerializeRaw`um objeto conectado a um objeto usando ; usar `CEditView::Serialize` em vez disso. A `SerializeRaw` função espera que o objeto de `Seek`arquivo `CSocketFile` tenha funções, como, que não tem.

Quando você `CArchive` `CSocketFile` usa `CSocket`com e , `CSocket::Receive` você pode encontrar `PumpMessages(FD_READ)`uma situação onde entra em um loop (por ) esperando a quantidade solicitada de bytes. Isso porque os soquetes do Windows permitem `CSocketFile` `CSocket` apenas uma chamada de recv por notificação FD_READ, mas e permitem várias chamadas de recv por FD_READ. Se você receber uma FD_READ quando não há dados para ler, o aplicativo é travado. Se você nunca tiver outra FD_READ, o aplicativo pára de se comunicar sobre o soquete.

Você pode resolver este problema da seguinte forma. No `OnReceive` método da sua classe `CAsyncSocket::IOCtl(FIONREAD, ...)` de soquete, ligue antes de chamar o `Serialize` método da sua classe de mensagem quando os dados esperados a serem lidos na tomada excedem o tamanho de um pacote TCP (unidade de transmissão máxima do meio de rede, geralmente pelo menos 1096 bytes). Se o tamanho dos dados disponíveis for menor do que o necessário, aguarde que todos os dados sejam recebidos e, em seguida, inicie a operação de leitura.

No exemplo a `m_dwExpected` seguir, está o número aproximado de bytes que o usuário espera receber. Presume-se que você o declare em outro lugar em seu código.

[!code-cpp[NVC_MFCSocketThread#4](../../mfc/reference/codesnippet/cpp/csocketfile-class_1.cpp)]

Para obter mais informações, consulte [Soquetes do Windows em MFC,](../../mfc/windows-sockets-in-mfc.md) [Soquetes do Windows: Usando Soquetes com Arquivos,](../../mfc/windows-sockets-using-sockets-with-archives.md)bem como [API do Windows Sockets 2](/windows/win32/WinSock/windows-sockets-start-page-2).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

`CSocketFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxsock.h

## <a name="csocketfilecsocketfile"></a><a name="csocketfile"></a>Arquivo de csocket::CSocketFile

Constrói um objeto `CSocketFile`.

```
explicit CSocketFile(
    CSocket* pSocket,
    BOOL bArchiveCompatible = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pSocket*<br/>
O soquete `CSocketFile` para fixar ao objeto.

*bArchiveCompatible*<br/>
Especifica se o objeto de arquivo `CArchive` é para uso com um objeto. Passe FALSO somente se quiser `CSocketFile` usar o objeto de forma autônoma, `CFile` como faria com um objeto autônomo, com certas limitações. Este sinalizador altera `CArchive` a forma `CSocketFile` como o objeto conectado ao objeto gerencia seu buffer para leitura.

### <a name="remarks"></a>Comentários

O destructor do objeto se desassocia do objeto do soquete quando o objeto sai do escopo ou é excluído.

> [!NOTE]
> A `CSocketFile` também pode ser usado como um `CArchive` arquivo (limitado) sem um objeto. Por padrão, `CSocketFile` o parâmetro *bArchiveCompatible* do construtor é TRUE. Isso especifica que o objeto de arquivo é para uso com um arquivo. Para usar o objeto de arquivo sem um arquivo, passe FALSE no parâmetro *bArchiveCompatible.*

Em seu modo "compatível `CSocketFile` com arquivamento", um objeto proporciona melhor desempenho e reduz o perigo de um "impasse". Um impasse ocorre quando tanto os soquetes de envio quanto de recebimento estão esperando um pelo outro, ou por um recurso comum. Essa situação pode `CArchive` ocorrer se `CSocketFile` o objeto funcionasse com a forma como funciona com um `CFile` objeto. Com `CFile`, o arquivo pode assumir que se ele recebe menos bytes do que solicitado, o fim do arquivo foi alcançado.

Com, `CSocketFile`no entanto, os dados são baseados em mensagens; o buffer pode conter várias mensagens, portanto, receber menos do que o número de bytes solicitados não implica fim do arquivo. O aplicativo não bloqueia neste caso `CFile`como poderia , e pode continuar lendo mensagens do buffer até que o buffer esteja vazio. A função [CArchive::IsBufferEmpty](../../mfc/reference/carchive-class.md#isbufferempty) é útil para monitorar o estado do buffer do arquivo em tal caso.

Para obter mais informações `CSocketFile`sobre o uso de , consulte os artigos [Soquetes do Windows: Usando Soquetes com Arquivos](../../mfc/windows-sockets-using-sockets-with-archives.md) e [Soquetes do Windows: Exemplo de Soquetes Usando Arquivos](../../mfc/windows-sockets-example-of-sockets-using-archives.md).

## <a name="see-also"></a>Confira também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CAsyncSocket](../../mfc/reference/casyncsocket-class.md)<br/>
[Classe CSocket](../../mfc/reference/csocket-class.md)
