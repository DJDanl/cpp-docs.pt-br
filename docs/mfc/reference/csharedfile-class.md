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
ms.openlocfilehash: 74a34ec169868d3e28f78f33da38dbda21ef23b3
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502609"
---
# <a name="csharedfile-class"></a>Classe CSharedFile

A classe derivada de [CMemFile](../../mfc/reference/cmemfile-class.md)que oferece suporte a arquivos de memória compartilhada.

## <a name="syntax"></a>Sintaxe

```
class CSharedFile : public CMemFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSharedFile::CSharedFile](#csharedfile)|Constrói um objeto `CSharedFile`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSharedFile::Detach](#detach)|Fecha o arquivo de memória compartilhada e retorna o identificador de seu bloco de memória.|
|[CSharedFile::SetHandle](#sethandle)|Anexa o arquivo de memória compartilhada a um bloco de memória.|

## <a name="remarks"></a>Comentários

Os arquivos de memória se comportam como arquivos de disco. A diferença é que um arquivo de memória é armazenado em RAM em vez de em disco. Um arquivo de memória é útil para um armazenamento temporário rápido ou para transferir bytes brutos ou objetos serializados entre processos independentes.

Arquivos de memória compartilhada diferem de outros arquivos de memória nessa memória para eles são alocados com a função do Windows [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) . A `CSharedFile` classe armazena dados em um bloco de memória alocado globalmente (criado `GlobalAlloc`usando), e esse bloco de memória pode ser compartilhado usando o DDE, a área de transferência ou outras operações de transferência de dados uniformes OLE/ `IDataObject`com, por exemplo, usando.

`GlobalAlloc`Retorna um identificador HGLOBAL em vez de um ponteiro para a memória, como o ponteiro retornado por [malloc](../../c-runtime-library/reference/malloc.md). O identificador HGLOBAL é necessário em determinados aplicativos. Por exemplo, para colocar dados na área de transferência, você precisa de um identificador HGLOBAL.

`CSharedFile`o não usa arquivos mapeados por memória e os dados não podem ser compartilhados diretamente entre processos.

`CSharedFile`os objetos podem alocar automaticamente sua própria memória. Ou você pode anexar seu próprio bloco de memória ao `CSharedFile` objeto chamando [CSharedFile:: SetHandle](#sethandle). Em ambos os casos, a memória para aumentar o arquivo de memória automaticamente `nGrowBytes`é alocada em incrementos de tamanho, se `nGrowBytes` não for zero.

Para obter mais informações, consulte o artigo [arquivos em MFC](../../mfc/files-in-mfc.md) e [manipulação de arquivos](../../c-runtime-library/file-handling.md) na referência da biblioteca de tempo de *execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[CMemFile](../../mfc/reference/cmemfile-class.md)

`CSharedFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv. h

##  <a name="csharedfile"></a>  CSharedFile::CSharedFile

Constrói um `CSharedFile` objeto e aloca memória para ele.

```
CSharedFile(
    UINT nAllocFlags = GMEM_DDESHARE | GMEM_MOVEABLE,
    UINT nGrowBytes = 4096);
```

### <a name="parameters"></a>Parâmetros

*nAllocFlags*<br/>
Sinalizadores que indicam como a memória deve ser alocada. Consulte [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) para obter uma lista de valores de sinalizador válidos.

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

Você pode reabri-lo chamando [SetHandle](#sethandle), usando o identificador retornado por **desanexar**.

##  <a name="sethandle"></a>  CSharedFile::SetHandle

Chame essa função para anexar um bloco de memória global ao `CSharedFile` objeto.

```
void SetHandle(
    HGLOBAL hGlobalMemory,
    BOOL bAllowGrow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*hGlobalMemory*<br/>
Manipule a memória global a ser anexada ao `CSharedFile`.

*bAllowGrow*<br/>
Especifica se o bloco de memória tem permissão para aumentar.

### <a name="remarks"></a>Comentários

Se *bAllowGrow* for diferente de zero, o tamanho do bloco de memória será aumentado conforme necessário, por exemplo, se você tentar gravar mais bytes no arquivo do que o tamanho do bloco de memória.

## <a name="see-also"></a>Consulte também

[Classe CMemFile](../../mfc/reference/cmemfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMemFile](../../mfc/reference/cmemfile-class.md)
