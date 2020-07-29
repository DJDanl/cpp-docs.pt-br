---
title: Classe CMemFile
description: Descreve as funções disponíveis na classe CMemFile, que permite que você trabalhe com arquivos de memória.
ms.date: 07/23/2020
f1_keywords:
- CMemFile
- AFX/CMemFile
- AFX/CMemFile::CMemFile
- AFX/CMemFile::Attach
- AFX/CMemFile::Detach
- AFX/CMemFile::Alloc
- AFX/CMemFile::Free
- AFX/CmemFile::GetBufferPtr
- AFX/CMemFile::GrowFile"
- AFX/CMemFile::Memcpy
- AFX/CMemFile::Realloc
helpviewer_keywords:
- CMemFile [MFC], CMemFile
- CMemFile [MFC], Attach
- CMemFile [MFC], Detach
- CMemFile [MFC], Alloc
- CMemFile [MFC], Free
- CMemFile [MFC], GetBufferPtr
- CMemFile [MFC], GrowFile
- CMemFile [MFC], Memcpy
- CMemFile [MFC], Realloc
ms.assetid: 20e86515-e465-4f73-b2ea-e49789d63165
ms.openlocfilehash: edd1d8b8d3979427602bdb61fc7647aec15d58b5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222934"
---
# <a name="cmemfile-class"></a>Classe CMemFile

A classe derivada de [testcfile](../../mfc/reference/cfile-class.md)que dá suporte a arquivos de memória.

## <a name="syntax"></a>Sintaxe

```
class CMemFile : public CFile
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemFile::CMemFile](#cmemfile)|Constrói um objeto de arquivo de memória.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMemFile:: Attach](#attach)|Anexa um bloco de memória para `CMemFile` .|
|[CMemFile::D Etach](#detach)|Desanexa o bloco de memória de `CMemFile` e retorna um ponteiro para o bloco de memória desanexado.|
|[CMemFile::GetBufferPtr](#getbufferptr)|Obtenha ou grave no buffer de memória que faz o backup de um arquivo de memória.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMemFile:: Alloc](#alloc)|Substituir para modificar o comportamento de alocação de memória.|
|[CMemFile:: Free](#free)|Substituir para modificar o comportamento de desalocação de memória.|
|[CMemFile:: Growfile](#growfile)|Substituir para modificar o comportamento ao aumentar um arquivo.|
|[CMemFile:: memcpy](#memcpy)|Substitua para modificar o comportamento de cópia da memória ao ler e gravar arquivos.|
|[CMemFile:: Realloc](#realloc)|Substituir para modificar o comportamento de realocação de memória.|

## <a name="remarks"></a>Comentários

Esses arquivos de memória se comportam como arquivos de disco, exceto que o arquivo é armazenado em RAM em vez de em disco. Um arquivo de memória é útil para:

- armazenamento temporário rápido
- Transferindo bytes brutos entre processos independentes
- Transferindo objetos serializados entre processos independentes

`CMemFile`os objetos podem alocar automaticamente sua própria memória. Ou você pode anexar seu próprio bloco de memória ao `CMemFile` objeto chamando [Attach](#attach). Em ambos os casos, a memória para aumentar o arquivo de memória automaticamente é alocada em `nGrowBytes` incrementos de tamanho, se `nGrowBytes` não for zero.

O bloco de memória será excluído automaticamente após a destruição do `CMemFile` objeto se a memória tiver sido alocada originalmente pelo `CMemFile` objeto; caso contrário, você será responsável por desalocar a memória que você anexou ao objeto.

Você pode acessar o bloco de memória por meio do ponteiro fornecido ao desanexá-lo do `CMemFile` objeto chamando [Detach](#detach).

O uso mais comum de `CMemFile` é criar um `CMemFile` objeto e usá-lo chamando as funções de membro de [testcfile](../../mfc/reference/cfile-class.md) . A criação de uma `CMemFile` abre automaticamente: você não chama [testcfile:: Open](../../mfc/reference/cfile-class.md#open), que é usado somente para arquivos de disco. Como `CMemFile` o não usa um arquivo de disco, o membro de dados `CFile::m_hFile` não é usado.

As `CFile` funções de membro [Duplicate](../../mfc/reference/cfile-class.md#duplicate), [LockRange](../../mfc/reference/cfile-class.md#lockrange)e [UnlockRange](../../mfc/reference/cfile-class.md#unlockrange) não são implementadas para `CMemFile` . Se você chamar essas funções em um `CMemFile` objeto, obterá um [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

`CMemFile`usa as funções de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md), [realloc](../../c-runtime-library/reference/realloc.md)e [Free](../../c-runtime-library/reference/free.md) para alocar, realocar e desalocar memória; e o [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md) intrínseco para bloquear a memória de cópia durante a leitura e gravação. Se você quiser alterar esse comportamento ou o comportamento quando o `CMemFile` aumentar um arquivo, derive sua própria classe de `CMemFile` e substitua as funções apropriadas.

Para obter mais informações sobre `CMemFile` o, consulte os artigos [arquivos em MFC](../../mfc/files-in-mfc.md) e [Gerenciamento de memória (MFC)](../../mfc/memory-management.md) e consulte [manipulação de arquivos](../../c-runtime-library/file-handling.md) na referência da biblioteca de *tempo de execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[OLE](../../mfc/reference/cfile-class.md)

`CMemFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="cmemfilealloc"></a><a name="alloc"></a>CMemFile:: Alloc

Essa função é chamada por `CMemFile` funções de membro.

```
virtual BYTE* Alloc(SIZE_T nBytes);
```

### <a name="parameters"></a>parâmetros

*nBytes*<br/>
Número de bytes de memória a serem alocados.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o bloco de memória que foi alocado ou nulo se a alocação falhar.

### <a name="remarks"></a>Comentários

Substitua essa função para implementar a alocação de memória personalizada. Se você substituir essa função, provavelmente desejará substituir [Free](#free) e [realloc](#realloc) também.

A implementação padrão usa a função de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md) para alocar memória.

## <a name="cmemfileattach"></a><a name="attach"></a>CMemFile:: Attach

Chame essa função para anexar um bloco de memória ao `CMemFile` .

```cpp
void Attach(
    BYTE* lpBuffer,
    UINT nBufferSize,
    UINT nGrowBytes = 0);
```

### <a name="parameters"></a>parâmetros

*lpBuffer*<br/>
Ponteiro para o buffer a ser anexado `CMemFile` .

*nBufferSize*<br/>
Um inteiro que especifica o tamanho do buffer em bytes.

*nGrowBytes*<br/>
O incremento de alocação de memória em bytes.

### <a name="remarks"></a>Comentários

Isso faz com que `CMemFile` o use o bloco de memória como o arquivo de memória.

Se *nGrowBytes* for 0, `CMemFile` o tamanho do arquivo será definido como *nBufferSize*. Isso significa que os dados no bloco de memória antes de ele ser anexado `CMemFile` serão usados como o arquivo. Os arquivos de memória criados dessa maneira não podem ser expandidos.

Uma vez que o arquivo não pode ser aumentado, tenha cuidado para não `CMemFile` tentar aumentar o arquivo. Por exemplo, não chame as `CMemFile` substituições de [testcfile: Write](../../mfc/reference/cfile-class.md#write) para gravação após o final ou não chame [testcfile: SetLength](../../mfc/reference/cfile-class.md#setlength) com um comprimento maior que *nBufferSize*.

Se *nGrowBytes* for maior que 0, `CMemFile` o irá ignorar o conteúdo do bloco de memória que você anexou. Você precisará escrever o conteúdo do arquivo de memória do zero usando a `CMemFile` substituição de `CFile::Write` . Se você tentar gravar após o final do arquivo ou aumentar o arquivo chamando a `CMemFile` substituição de `CFile::SetLength` , o `CMemFile` aumentará a alocação de memória em incrementos de *nGrowBytes*. Aumentar a alocação de memória falhará se o bloco de memória que você passar para `Attach` não tiver sido alocado com um método compatível com [Alloc](#alloc). Para ser compatível com a implementação padrão do `Alloc` , você deve alocar a memória com a função de biblioteca de tempo de execução [malloc](../../c-runtime-library/reference/malloc.md) ou [calloc](../../c-runtime-library/reference/calloc.md).

## <a name="cmemfilecmemfile"></a><a name="cmemfile"></a>CMemFile::CMemFile

A primeira sobrecarga abre um arquivo de memória vazio.

```
CMemFile(UINT nGrowBytes = 1024);

CMemFile(
    BYTE* lpBuffer,
    UINT nBufferSize,
    UINT nGrowBytes = 0);
```

### <a name="parameters"></a>parâmetros

*nGrowBytes*<br/>
O incremento de alocação de memória em bytes.

*lpBuffer* Ponteiro para um buffer que recebe informações do tamanho *nBufferSize*.

*nBufferSize*<br/>
Um inteiro que especifica o tamanho do buffer de arquivo, em bytes.

### <a name="remarks"></a>Comentários

O arquivo é aberto pelo construtor. Não chame [testcfile:: Open](../../mfc/reference/cfile-class.md#open).

A segunda sobrecarga age da mesma forma como se você tiver usado o primeiro construtor e imediatamente chamado [Attach](#attach) com os mesmos parâmetros. Para obter detalhes, consulte `Attach`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#36](../../atl-mfc-shared/reference/codesnippet/cpp/cmemfile-class_1.cpp)]

## <a name="cmemfiledetach"></a><a name="detach"></a>CMemFile::D Etach

Chame essa função para obter um ponteiro para o bloco de memória que está sendo usado pelo `CMemFile` .

```
BYTE* Detach();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o bloco de memória que contém o conteúdo do arquivo de memória.

### <a name="remarks"></a>Comentários

Chamar essa função também fecha o `CMemFile` . Você pode anexar novamente o bloco de memória ao `CMemFile` chamando [Attach](#attach). Se você quiser anexar novamente o arquivo e usar os dados nele, deverá chamar [testcfile:: GetLength](../../mfc/reference/cfile-class.md#getlength) para obter o comprimento do arquivo antes de chamar `Detach` . Se você anexar um bloco de memória ao para `CMemFile` que possa usar seus dados ( `nGrowBytes` = = 0), não poderá aumentar o arquivo de memória.

## <a name="cmemfilefree"></a><a name="free"></a>CMemFile:: Free

Essa função é chamada por `CMemFile` funções de membro.

```
virtual void Free(BYTE* lpMem);
```

### <a name="parameters"></a>parâmetros

*lpMem*<br/>
Ponteiro para a memória a ser desalocada.

### <a name="remarks"></a>Comentários

Substitua essa função para implementar a desalocação de memória personalizada. Se você substituir essa função, provavelmente desejará substituir [Alloc](#alloc) e [realloc](#realloc) também.

## <a name="cmemfilegetbufferptr"></a><a name="getbufferptr"></a>CMemFile::GetBufferPtr

Obtenha ou grave no buffer de memória que faz o backup de um arquivo de memória.

```cpp
virtual UINT GetBufferPtr(
    UINT nCommand,
    UINT nCount = 0,
    void** ppBufStart = NULL,
    void** ppBufMax = NULL
);
```

### <a name="parameters"></a>parâmetros

*Ncomando*<br/>
O [bufferCommand](buffercommand-enumeration.md) a ser executado ( `bufferCheck` , `bufferCommit` , `bufferRead` ou `bufferWrite` ).

*nCount*<br/>
Dependendo do *ncomando*, o número de bytes no buffer a serem lidos, gravados ou confirmados. Ao ler do buffer, especifique-1 para retornar um buffer da posição atual até o final do arquivo.

*ppBufStart*<br/>
fora O início do buffer. Deve ser `NULL` quando *ncomando* é `bufferCommit` .

*ppBufMax*<br/>
fora O final do buffer. Deve ser `NULL` quando ncomando é `bufferCommit` .

### <a name="return-value"></a>Valor retornado

| valor do *comando* | Valor retornado |
|--|--|
| `buffercheck` | Retorna [bufferDirect](buffercommand-enumeration.md) se o buffer direto tiver suporte; caso contrário, 0. |
| `bufferCommit` | Retorna `0` |
| `bufferRead` ou `bufferWrite` | Retorna o número de bytes no espaço de buffer retornado. *ppBufStart* e *ppBufMax* apontam para o início e o fim do buffer de leitura/gravação.  |

### <a name="remarks"></a>Comentários

A posição atual no buffer de memória ( `m_nPosition` ) é avançada das seguintes maneiras, dependendo do *ncomando*:

| *Ncomando* | posição do buffer |
|-|-|
| `bufferCommit` | A posição atual avança pelo tamanho do buffer confirmado. |
| `bufferRead` | A posição atual avança pelo tamanho do buffer de leitura. |

## <a name="cmemfilegrowfile"></a><a name="growfile"></a>CMemFile:: Growfile

Essa função é chamada por várias funções de `CMemFile` membro.

```
virtual void GrowFile(SIZE_T dwNewLen);
```

### <a name="parameters"></a>parâmetros

*dwNewLen*<br/>
Novo tamanho do arquivo de memória.

### <a name="remarks"></a>Comentários

Você pode substituí-lo se quiser alterar o grau `CMemFile` de crescimento do arquivo. A implementação padrão chama [realloc](#realloc) para aumentar um bloco existente (ou [alocar](#alloc) para criar um bloco de memória), Alocando memória em múltiplos do `nGrowBytes` valor especificado no construtor ou na chamada de [anexo](#attach) .

## <a name="cmemfilememcpy"></a><a name="memcpy"></a>CMemFile:: memcpy

Essa função é chamada pelas `CMemFile` substituições de [testcfile:: Read](../../mfc/reference/cfile-class.md#read) e [testcfile:: Write](../../mfc/reference/cfile-class.md#write) para transferir dados de e para o arquivo de memória.

```
virtual BYTE* Memcpy(
    BYTE* lpMemTarget,
    const BYTE* lpMemSource,
    SIZE_T nBytes);
```

### <a name="parameters"></a>parâmetros

*lpMemTarget*<br/>
Ponteiro para o bloco de memória no qual a memória de origem será copiada.

*lpMemSource*<br/>
Ponteiro para o bloco de memória de origem.

*nBytes*<br/>
Número de bytes a serem copiados.

### <a name="return-value"></a>Valor retornado

Uma cópia de *lpMemTarget*.

### <a name="remarks"></a>Comentários

Substitua essa função se desejar alterar a forma como essas cópias de memória são substituídas `CMemFile` .

## <a name="cmemfilerealloc"></a><a name="realloc"></a>CMemFile:: Realloc

Essa função é chamada por `CMemFile` funções de membro.

```
virtual BYTE* Realloc(
    BYTE* lpMem,
    SIZE_T nBytes);
```

### <a name="parameters"></a>parâmetros

*lpMem*<br/>
Um ponteiro para o bloco de memória a ser realocado.

*nBytes*<br/>
Novo tamanho para o bloco de memória.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o bloco de memória que foi realocado (e possivelmente movido) ou nulo se a realocação falhar.

### <a name="remarks"></a>Comentários

Substitua essa função para implementar a realocação de memória personalizada. Se você substituir essa função, provavelmente desejará substituir [Alloc](#alloc) e [Free](#free) também.

## <a name="see-also"></a>Confira também

[Classe de testcfile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
