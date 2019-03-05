---
title: Classe CSharedFile
ms.date: 11/04/2016
f1_keywords:
- CSharedFile
- AFXADV/CSharedFile
- AFXADV/CSharedFile::CSharedFile
- AFXADV/CSharedFile::Detach
- AFXADV/CSharedFile::SetHandle
helpviewer_keywords:
- CSharedFile [MFC], CSharedFile
- CSharedFile [MFC], Detach
- CSharedFile [MFC], SetHandle
ms.assetid: 5d000422-9ede-4318-a8c9-f7412b674f39
ms.openlocfilehash: e86e64c1de232aba0c17a0fdfb3600e480567a57
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57273069"
---
# <a name="csharedfile-class"></a>Classe CSharedFile

O [CMemFile](../../mfc/reference/cmemfile-class.md)-compartilhado de uma classe derivada que dá suporte a arquivos de memória.

## <a name="syntax"></a>Sintaxe

```
class CSharedFile : public CMemFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSharedFile::CSharedFile](#csharedfile)|Constrói um objeto `CSharedFile`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSharedFile::Detach](#detach)|Fecha o arquivo de memória compartilhada e retorna o identificador do seu bloco de memória.|
|[CSharedFile::SetHandle](#sethandle)|Anexa o arquivo de memória compartilhada para um bloco de memória.|

## <a name="remarks"></a>Comentários

Arquivos de memória se comportam como arquivos de disco, exceto que o arquivo é armazenado na RAM, em vez de no disco. Um arquivo de memória é útil para armazenamento temporário rápido ou para a transferência de bytes brutos ou serializada objetos entre processos independentes.

Arquivos de memória compartilhada diferem de outros arquivos de memória em que a memória para eles é alocada com o [GlobalAlloc](/windows/desktop/api/winbase/nf-winbase-globalalloc) função do Windows. O `CSharedFile` classe armazena dados em um bloco de memória global alocado (criado usando `GlobalAlloc`), e este bloco de memória pode ser compartilhado usando DDE, a área de transferência ou outras OLE/COM operações de transferência uniforme de dados, de, por exemplo, usando `IDataObject`.

`GlobalAlloc` Retorna um HGLOBAL manipular em vez de um ponteiro de memória, como o ponteiro retornado por [malloc](../../c-runtime-library/reference/malloc.md). O identificador HGLOBAL é necessária em determinados aplicativos. Por exemplo, para colocar dados na área de transferência, você precisa um identificador HGLOBAL.

Observe que `CSharedFile` não arquivos mapeados na memória de uso e os dados não podem ser compartilhados diretamente entre processos.

`CSharedFile` objetos podem alocar automaticamente sua própria memória, ou você pode anexar seu próprio bloco de memória para o `CSharedFile` objeto chamando [CSharedFile::SetHandle](#sethandle). Em ambos os casos, a memória para aumentar o arquivo de memória automaticamente é alocada em `nGrowBytes`-em incrementos de tamanho se `nGrowBytes` não é zero.

Para obter mais informações, consulte o artigo [arquivos no MFC](../../mfc/files-in-mfc.md) e [tratamento de arquivos](../../c-runtime-library/file-handling.md) no *referência da biblioteca de tempo de execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[CMemFile](../../mfc/reference/cmemfile-class.md)

`CSharedFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv.h

##  <a name="csharedfile"></a>  CSharedFile::CSharedFile

Constrói um `CSharedFile` de objeto e aloca memória para ela.

```
CSharedFile(
    UINT nAllocFlags = GMEM_DDESHARE | GMEM_MOVEABLE,
    UINT nGrowBytes = 4096);
```

### <a name="parameters"></a>Parâmetros

*nAllocFlags*<br/>
Sinalizadores que indica como a memória é a ser alocado. Ver [GlobalAlloc](/windows/desktop/api/winbase/nf-winbase-globalalloc) para obter uma lista de valores de sinalizador válido.

*nGrowBytes*<br/>
O incremento de alocação de memória em bytes.

##  <a name="detach"></a>  CSharedFile::Detach

Chame essa função para fechar o arquivo de memória e desanexá-lo do bloco de memória.

```
HGLOBAL Detach();
```

### <a name="return-value"></a>Valor de retorno

O identificador do bloco de memória que contém o conteúdo do arquivo de memória.

### <a name="remarks"></a>Comentários

Você pode reabri-lo chamando [SetHandle](#sethandle), usando o identificador retornado pela **desanexar**.

##  <a name="sethandle"></a>  CSharedFile::SetHandle

Chame essa função para anexar um bloco de memória global para o `CSharedFile` objeto.

```
void SetHandle(
    HGLOBAL hGlobalMemory,
    BOOL bAllowGrow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*hGlobalMemory*<br/>
Lidar com a memória global a ser anexado à `CSharedFile`.

*bAllowGrow*<br/>
Especifica se o bloco de memória tem permissão para crescer.

### <a name="remarks"></a>Comentários

Se *bAllowGrow* é diferente de zero, o tamanho do bloco de memória aumenta conforme necessário, por exemplo, se uma tentativa for feita para gravar o arquivo que foram alocados para o bloco de memória mais bytes.

## <a name="see-also"></a>Consulte também

[Classe CMemFile](../../mfc/reference/cmemfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMemFile](../../mfc/reference/cmemfile-class.md)
