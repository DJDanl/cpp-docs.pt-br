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
ms.openlocfilehash: e6a713ac9d9e906ec204d4a52b43ed51c08fd99c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318424"
---
# <a name="csharedfile-class"></a>Classe CSharedFile

A classe derivada do [CMemFile](../../mfc/reference/cmemfile-class.md)que suporta arquivos de memória compartilhada.

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
|[CSharedFile::Detach](#detach)|Fecha o arquivo de memória compartilhada e retorna a alça do bloco de memória.|
|[CSharedArquivo::SetHandle](#sethandle)|Anexa o arquivo de memória compartilhada a um bloco de memória.|

## <a name="remarks"></a>Comentários

Arquivos de memória se comportam como arquivos de disco. A diferença é que um arquivo de memória é armazenado na RAM em vez de em disco. Um arquivo de memória é útil para armazenamento temporário rápido, ou para transferir bytes brutos ou objetos serializados entre processos independentes.

Os arquivos de memória compartilhados diferem de outros arquivos de memória nessa memória para eles é alocado com a função [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) Windows. A `CSharedFile` classe armazena dados em um bloco de `GlobalAlloc`memória alocado globalmente (criado usando), e esse bloco de memória pode ser compartilhado usando ODDE, a Área de Transferência ou outras operações de transferência de dados uniformes OLE/COM, por exemplo, usando `IDataObject`.

`GlobalAlloc`retorna uma alça HGLOBAL em vez de um ponteiro para a memória, como o ponteiro devolvido por [malloc](../../c-runtime-library/reference/malloc.md). O cabo HGLOBAL é necessário em determinadas aplicações. Por exemplo, para colocar dados na área de transferência, você precisa de uma alça HGLOBAL.

`CSharedFile`não usa arquivos mapeados pela memória e os dados não podem ser compartilhados diretamente entre os processos.

`CSharedFile`objetos podem alocar automaticamente sua própria memória. Ou, você pode anexar seu `CSharedFile` próprio bloco de memória ao objeto chamando [CSharedFile::SetHandle](#sethandle). Em ambos os casos, a memória para o `nGrowBytes`crescimento do `nGrowBytes` arquivo de memória é alocada automaticamente em incrementos de tamanho, se não for zero.

Para obter mais informações, consulte o artigo [Arquivos em MFC](../../mfc/files-in-mfc.md) e [Tratamento de Arquivos](../../c-runtime-library/file-handling.md) na Referência de Biblioteca em Tempo de *Execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

[Cmemfile](../../mfc/reference/cmemfile-class.md)

`CSharedFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv.h

## <a name="csharedfilecsharedfile"></a><a name="csharedfile"></a>CSharedFile::CSharedFile

Constrói um `CSharedFile` objeto e aloca memória para ele.

```
CSharedFile(
    UINT nAllocFlags = GMEM_DDESHARE | GMEM_MOVEABLE,
    UINT nGrowBytes = 4096);
```

### <a name="parameters"></a>Parâmetros

*nAllocFlags*<br/>
Sinalizadores indicando como a memória deve ser alocada. Consulte [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) para obter uma lista de valores de bandeira válidos.

*Ngrowbytes*<br/>
O incremento de alocação de memória em bytes.

## <a name="csharedfiledetach"></a><a name="detach"></a>CSharedFile::Detach

Chame esta função para fechar o arquivo de memória e desconectá-lo do bloco de memória.

```
HGLOBAL Detach();
```

### <a name="return-value"></a>Valor retornado

A alça do bloco de memória que contém o conteúdo do arquivo de memória.

### <a name="remarks"></a>Comentários

Você pode reabri-lo chamando [SetHandle](#sethandle), usando a alça retornada pelo **Despaque**.

## <a name="csharedfilesethandle"></a><a name="sethandle"></a>CSharedArquivo::SetHandle

Chame esta função para anexar um `CSharedFile` bloco de memória global ao objeto.

```
void SetHandle(
    HGLOBAL hGlobalMemory,
    BOOL bAllowGrow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*hGlobalMemory*<br/>
Manuseie a memória global `CSharedFile`a ser anexada ao .

*bAllowGrow*<br/>
Especifica se o bloco de memória pode crescer.

### <a name="remarks"></a>Comentários

Se *bAllowGrow* não for zero, o tamanho do bloco de memória será aumentado conforme necessário, por exemplo, se você tentar escrever mais bytes para o arquivo do que o tamanho do bloco de memória.

## <a name="see-also"></a>Confira também

[Classe CMemFile](../../mfc/reference/cmemfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMemFile](../../mfc/reference/cmemfile-class.md)
