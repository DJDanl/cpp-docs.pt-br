---
title: Classe CMemFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMemFile
- AFX/CMemFile
- AFX/CMemFile::CMemFile
- AFX/CMemFile::Attach
- AFX/CMemFile::Detach
- AFX/CMemFile::Alloc
- AFX/CMemFile::Free
- AFX/CMemFile::GrowFile
- AFX/CMemFile::Memcpy
- AFX/CMemFile::Realloc
dev_langs:
- C++
helpviewer_keywords:
- CMemFile [MFC], CMemFile
- CMemFile [MFC], Attach
- CMemFile [MFC], Detach
- CMemFile [MFC], Alloc
- CMemFile [MFC], Free
- CMemFile [MFC], GrowFile
- CMemFile [MFC], Memcpy
- CMemFile [MFC], Realloc
ms.assetid: 20e86515-e465-4f73-b2ea-e49789d63165
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 90203a2e4fc29b28e6c75193ed1db35e25044951
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50076952"
---
# <a name="cmemfile-class"></a>Classe CMemFile

O [CFile](../../mfc/reference/cfile-class.md)-derivado da classe que dá suporte a arquivos de memória.

## <a name="syntax"></a>Sintaxe

```
class CMemFile : public CFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemFile::CMemFile](#cmemfile)|Constrói um objeto de arquivo de memória.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemFile::Attach](#attach)|Anexa um bloco de memória para `CMemFile`.|
|[CMemFile::Detach](#detach)|Desanexa o bloco de memória de `CMemFile` e retorna um ponteiro para o bloco de memória desanexado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMemFile::Alloc](#alloc)|Substituição para modificar o comportamento de alocação de memória.|
|[CMemFile::Free](#free)|Substituição para modificar o comportamento de desalocação de memória.|
|[CMemFile::GrowFile](#growfile)|Substituição para modificar o comportamento ao aumentar um arquivo.|
|[CMemFile::Memcpy](#memcpy)|Substitua para modificar o comportamento de cópia de memória ao ler e gravar arquivos.|
|[CMemFile::Realloc](#realloc)|Substituição para modificar o comportamento de realocação de memória.|

## <a name="remarks"></a>Comentários

Esses arquivos de memória se comportam como arquivos de disco, exceto que o arquivo é armazenado na RAM, em vez de no disco. Um arquivo de memória é útil para armazenamento temporário rápido ou para a transferência de bytes brutos ou serializada objetos entre processos independentes.

`CMemFile` objetos podem alocar automaticamente sua própria memória, ou você pode anexar seu próprio bloco de memória para o `CMemFile` objeto chamando [Attach](#attach). Em ambos os casos, a memória para aumentar o arquivo de memória automaticamente é alocada em `nGrowBytes`-em incrementos de tamanho se `nGrowBytes` não é zero.

O bloco de memória será excluído automaticamente após a destruição do `CMemFile` do objeto se a memória foi originalmente alocada pelo `CMemFile` objeto; caso contrário, você é responsável por desalocar a memória anexado ao objeto.

Você pode acessar o bloco de memória através do ponteiro fornecido quando você desanexá-lo a partir de `CMemFile` objeto chamando [desanexar](#detach).

O uso mais comum de `CMemFile` é criar um `CMemFile` do objeto e usá-lo chamando [CFile](../../mfc/reference/cfile-class.md) funções de membro. Observe que criar uma `CMemFile` abre automaticamente: você não chamar [CFile::Open](../../mfc/reference/cfile-class.md#open), que é usado somente para arquivos de disco. Porque `CMemFile` não usa um arquivo de disco, o membro de dados `CFile::m_hFile` não é usado.

O `CFile` funções de membro [duplicar](../../mfc/reference/cfile-class.md#duplicate), [LockRange](../../mfc/reference/cfile-class.md#lockrange), e [UnlockRange](../../mfc/reference/cfile-class.md#unlockrange) não são implementadas para `CMemFile`. Se você chamar essas funções em um `CMemFile` do objeto, você obterá uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

`CMemFile` usa as funções de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md), [realloc](../../c-runtime-library/reference/realloc.md), e [gratuita](../../c-runtime-library/reference/free.md) para alocar, realocar e desalocar a memória; e o intrínseco [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md) para a memória de cópia do bloco ao ler e gravar. Se você gostaria de alterar esse comportamento ou o comportamento quando `CMemFile` cresce de um arquivo, derive sua própria classe de `CMemFile` e substituem as funções apropriadas.

Para obter mais informações sobre `CMemFile`, consulte os artigos [arquivos no MFC](../../mfc/files-in-mfc.md) e [gerenciamento de memória (MFC)](../../mfc/memory-management.md) e veja [tratamento de arquivos](../../c-runtime-library/file-handling.md) no *tempo de execução Referência da biblioteca*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

`CMemFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="alloc"></a>  CMemFile::Alloc

Essa função é chamada pelo `CMemFile` funções de membro.

```
virtual BYTE* Alloc(SIZE_T nBytes);
```

### <a name="parameters"></a>Parâmetros

*nBytes*<br/>
Número de bytes de memória a ser alocado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o bloco de memória que foi alocado, ou nulo se a alocação falhou.

### <a name="remarks"></a>Comentários

Substitua essa função para implementar a alocação de memória personalizado. Se você substituir essa função, você provavelmente desejará substituir [livre](#free) e [Realloc](#realloc) também.

A implementação padrão usa a função de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md) ao alocar memória.

##  <a name="attach"></a>  CMemFile::Attach

Chame essa função para anexar um bloco de memória para `CMemFile`.

```
void Attach(
    BYTE* lpBuffer,
    UINT nBufferSize,
    UINT nGrowBytes = 0);
```

### <a name="parameters"></a>Parâmetros

*lpBuffer*<br/>
Ponteiro para o buffer a ser anexado à `CMemFile`.

*nBufferSize*<br/>
Um inteiro que especifica o tamanho do buffer em bytes.

*nGrowBytes*<br/>
O incremento de alocação de memória em bytes.

### <a name="remarks"></a>Comentários

Isso faz com que `CMemFile` para usar o bloco de memória que o arquivo de memória.

Se *nGrowBytes* é 0, o `CMemFile` definirá o tamanho do arquivo como *nBufferSize*. Isso significa que os dados no bloco de memória antes que ele foi anexado ao `CMemFile` será usado como o arquivo. Arquivos de memória criados dessa maneira não podem ser aumentados.

Uma vez que o arquivo não pode ser expandido, tenha cuidado para não causar `CMemFile` para tentar aumentar o arquivo. Por exemplo, não chame o `CMemFile` substituições de [CFile:Write](../../mfc/reference/cfile-class.md#write) para gravar após o término ou não chame [CFile:SetLength](../../mfc/reference/cfile-class.md#setlength) com um comprimento maior que *nBufferSize*.

Se *nGrowBytes* for maior que 0, `CMemFile` irá ignorar o conteúdo do bloco de memória que você já anexou. Você precisará escrever o conteúdo do arquivo de memória do zero usando o `CMemFile` substituir de `CFile::Write`. Se você tentar gravar após o final do arquivo ou o tamanho do arquivo chamando o `CMemFile` substituir da `CFile::SetLength`, `CMemFile` aumentará a alocação de memória em incrementos de *nGrowBytes*. Aumentando a alocação de memória falhará se o bloco de memória que você passar para `Attach` não foi alocado com um método compatível com [Alloc](#alloc). Para ser compatível com a implementação padrão de `Alloc`, você deve alocar a memória com a função de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md) ou [calloc](../../c-runtime-library/reference/calloc.md).

##  <a name="cmemfile"></a>  CMemFile::CMemFile

A primeira sobrecarga abre um arquivo de memória vazia.

```
CMemFile(UINT nGrowBytes = 1024);

CMemFile(
    BYTE* lpBuffer,
    UINT nBufferSize,
    UINT nGrowBytes = 0);
```

### <a name="parameters"></a>Parâmetros

*nGrowBytes*<br/>
O incremento de alocação de memória em bytes.

*lpBuffe*r ponteiro para um buffer que recebe informações de tamanho *nBufferSize*.

*nBufferSize*<br/>
Um inteiro que especifica o tamanho do buffer de arquivo, em bytes.

### <a name="remarks"></a>Comentários

Observe que o arquivo é aberto pelo construtor e você não deve chamar [CFile::Open](../../mfc/reference/cfile-class.md#open).

A segunda sobrecarga age como se você usou o primeiro construtor e imediatamente chamado o mesmo [Attach](#attach) com os mesmos parâmetros. Consulte `Attach` para obter os detalhes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#36](../../atl-mfc-shared/reference/codesnippet/cpp/cmemfile-class_1.cpp)]

##  <a name="detach"></a>  CMemFile::Detach

Chame essa função para obter um ponteiro para o bloco de memória que está sendo usado por `CMemFile`.

```
BYTE* Detach();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o bloco de memória que contém o conteúdo do arquivo de memória.

### <a name="remarks"></a>Comentários

Chamar essa função também fecha o `CMemFile`. Você pode anexar novamente o bloco de memória `CMemFile` chamando [Attach](#attach). Se você quiser anexar novamente o arquivo e usar os dados contidos nela, você deve chamar [CFile::GetLength](../../mfc/reference/cfile-class.md#getlength) para obter o tamanho do arquivo antes de chamar `Detach`. Observe que, se você anexar um bloco de memória `CMemFile` para que você possa usar seus dados ( `nGrowBytes` = = 0), em seguida, você não poderá aumentar o arquivo de memória.

##  <a name="free"></a>  CMemFile::Free

Essa função é chamada pelo `CMemFile` funções de membro.

```
virtual void Free(BYTE* lpMem);
```

### <a name="parameters"></a>Parâmetros

*lpMem*<br/>
Ponteiro para a memória seja desalocada.

### <a name="remarks"></a>Comentários

Substitua essa função para implementar a desalocação de memória personalizado. Se você substituir essa função, você provavelmente desejará substituir [Alloc](#alloc) e [Realloc](#realloc) também.

##  <a name="growfile"></a>  CMemFile::GrowFile

Essa função é chamada por várias do `CMemFile` funções de membro.

```
virtual void GrowFile(SIZE_T dwNewLen);
```

### <a name="parameters"></a>Parâmetros

*dwNewLen*<br/>
Novo tamanho do arquivo de memória.

### <a name="remarks"></a>Comentários

Você pode substituí-la se você quiser alterar como `CMemFile` aumenta seu arquivo. A implementação padrão chama [Realloc](#realloc) cresça um bloco existente (ou [Alloc](#alloc) para criar um bloco de memória), alocação de memória em múltiplos do `nGrowBytes` especificado no construtor de valor ou [Attach](#attach) chamar.

##  <a name="memcpy"></a>  CMemFile::Memcpy

Essa função é chamada o `CMemFile` substituições de [CFile::Read](../../mfc/reference/cfile-class.md#read) e [CFile::Write](../../mfc/reference/cfile-class.md#write) para transferir dados de e para o arquivo de memória.

```
virtual BYTE* Memcpy(
    BYTE* lpMemTarget,
    const BYTE* lpMemSource,
    SIZE_T nBytes);
```

### <a name="parameters"></a>Parâmetros

*lpMemTarget*<br/>
Ponteiro para o bloco de memória no qual a memória de origem será copiada.

*lpMemSource*<br/>
Ponteiro para o bloco de memória do código-fonte.

*nBytes*<br/>
Número de bytes a serem copiados.

### <a name="return-value"></a>Valor de retorno

Uma cópia do *lpMemTarget*.

### <a name="remarks"></a>Comentários

Substituir essa função se você quiser alterar a maneira que `CMemFile` faz essas cópias de memória.

##  <a name="realloc"></a>  CMemFile::Realloc

Essa função é chamada pelo `CMemFile` funções de membro.

```
virtual BYTE* Realloc(
    BYTE* lpMem,
    SIZE_T nBytes);
```

### <a name="parameters"></a>Parâmetros

*lpMem*<br/>
Um ponteiro para o bloco de memória a ser realocados.

*nBytes*<br/>
Novo tamanho para o bloco de memória.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o bloco de memória que foi realocado (e possivelmente movido), ou nulo se a realocação de falha.

### <a name="remarks"></a>Comentários

Substitua essa função para implementar a realocação de memória personalizado. Se você substituir essa função, você provavelmente desejará substituir [Alloc](#alloc) e [gratuito](#free) também.

## <a name="see-also"></a>Consulte também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

