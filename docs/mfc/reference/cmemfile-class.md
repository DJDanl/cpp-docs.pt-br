---
title: Classe CMemFile
ms.date: 11/04/2016
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
ms.openlocfilehash: 46937795499fd9f697f9778c263a1ee011777c0d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370018"
---
# <a name="cmemfile-class"></a>Classe CMemFile

A [classe cfile](../../mfc/reference/cfile-class.md)derivada que suporta arquivos de memória.

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
|[CMemFile::Anexar](#attach)|Anexa um bloco de `CMemFile`memória a .|
|[CMemFile::Detach](#detach)|Destaca o bloco de `CMemFile` memória e retorna um ponteiro para o bloco de memória desconectado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMemFile::Alloc](#alloc)|Substituir para modificar o comportamento de alocação de memória.|
|[CMemFile::Grátis](#free)|Substituir para modificar o comportamento de desalocação da memória.|
|[CMemFile::GrowFile](#growfile)|Substituir para modificar o comportamento ao crescer um arquivo.|
|[CMemFile::Memcpy](#memcpy)|Substituir para modificar o comportamento da cópia de memória ao ler e escrever arquivos.|
|[CMemFile::Realloc](#realloc)|Substituir para modificar o comportamento de realocação de memória.|

## <a name="remarks"></a>Comentários

Esses arquivos de memória se comportam como arquivos de disco, exceto que o arquivo é armazenado em RAM em vez de em disco. Um arquivo de memória é útil para armazenamento temporário rápido ou para transferir bytes brutos ou objetos serializados entre processos independentes.

`CMemFile`objetos podem alocar automaticamente sua própria memória ou `CMemFile` você pode anexar seu próprio bloco de memória ao objeto chamando [Anexar](#attach). Em ambos os casos, a memória para o `nGrowBytes`crescimento do `nGrowBytes` arquivo de memória é alocada automaticamente em incrementos de tamanho, se não for zero.

O bloco de memória será automaticamente excluído `CMemFile` após a destruição do objeto `CMemFile` se a memória foi originalmente alocada pelo objeto; caso contrário, você é responsável por lidar com a memória que anexou ao objeto.

Você pode acessar o bloco de memória através do `CMemFile` ponteiro fornecido quando você desconectá-lo do objeto chamando [Desapego](#detach).

O uso mais `CMemFile` comum `CMemFile` é criar um objeto e usá-lo chamando funções de membro [CFile.](../../mfc/reference/cfile-class.md) Observe que `CMemFile` a criação de uma abre-lo automaticamente: você não chama [CFile::Open](../../mfc/reference/cfile-class.md#open), que é usado apenas para arquivos de disco. Como `CMemFile` não usa um arquivo de `CFile::m_hFile` disco, o membro de dados não é usado.

As `CFile` funções de membro [Duplicate,](../../mfc/reference/cfile-class.md#duplicate) [LockRange](../../mfc/reference/cfile-class.md#lockrange)e `CMemFile` [UnlockRange](../../mfc/reference/cfile-class.md#unlockrange) não são implementadas para . Se você chamar essas `CMemFile` funções em um objeto, você receberá uma [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).

`CMemFile`usa as funções de biblioteca de tempo de [execução malloc](../../c-runtime-library/reference/malloc.md), [realloc](../../c-runtime-library/reference/realloc.md), e [livre](../../c-runtime-library/reference/free.md) para alocar, realocar e desalocar a memória; e o [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md) intrínseco para bloquear a memória da cópia ao ler e escrever. Se você quiser mudar esse comportamento ou `CMemFile` o comportamento quando crescer `CMemFile` um arquivo, obtenha sua própria classe e anule as funções apropriadas.

Para obter `CMemFile`mais informações, consulte os artigos [Arquivos em MFC](../../mfc/files-in-mfc.md) e [MFC (Memory Management)](../../mfc/memory-management.md) e consulte [O manuseio de arquivos](../../c-runtime-library/file-handling.md) na referência da biblioteca em tempo de *execução*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

`CMemFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cmemfilealloc"></a><a name="alloc"></a>CMemFile::Alloc

Esta função é `CMemFile` chamada por funções de membro.

```
virtual BYTE* Alloc(SIZE_T nBytes);
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
Número de bytes de memória a serem alocados.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o bloco de memória que foi alocado ou NULL se a alocação falhar.

### <a name="remarks"></a>Comentários

Substituir esta função para implementar a alocação de memória personalizada. Se você substituir esta função, você provavelmente vai querer substituir [Free](#free) e [Realloc](#realloc) também.

A implementação padrão usa a função de biblioteca em tempo de [execução para](../../c-runtime-library/reference/malloc.md) alocar memória.

## <a name="cmemfileattach"></a><a name="attach"></a>CMemFile::Anexar

Chame esta função para anexar `CMemFile`um bloco de memória a .

```
void Attach(
    BYTE* lpBuffer,
    UINT nBufferSize,
    UINT nGrowBytes = 0);
```

### <a name="parameters"></a>Parâmetros

*Lpbuffer*<br/>
Ponteiro para o buffer a `CMemFile`ser anexado a .

*Nbuffersize*<br/>
Um inteiro que especifica o tamanho do buffer em bytes.

*Ngrowbytes*<br/>
O incremento de alocação de memória em bytes.

### <a name="remarks"></a>Comentários

Isso `CMemFile` faz com que use o bloco de memória como arquivo de memória.

Se *nGrowBytes* for `CMemFile` 0, definirá o comprimento do arquivo como *nBufferSize*. Isso significa que os dados no bloco de `CMemFile` memória antes de serem anexados serão usados como arquivo. Os arquivos de memória criados desta maneira não podem ser cultivados.

Uma vez que o arquivo não `CMemFile` pode ser cultivado, tenha cuidado para não causar para tentar crescer o arquivo. Por exemplo, não chame `CMemFile` as substituições de [CFile:Write](../../mfc/reference/cfile-class.md#write) para gravar além do final ou não chamar [CFile:SetLength](../../mfc/reference/cfile-class.md#setlength) com um comprimento maior que *nBufferSize*.

Se *nGrowBytes* for maior `CMemFile` que 0, ignorará o conteúdo do bloco de memória que você anexou. Você terá que escrever o conteúdo do arquivo `CMemFile` de memória `CFile::Write`do zero usando o dispositivo de . Se você tentar escrever além do final do arquivo `CMemFile` ou aumentar `CFile::SetLength` `CMemFile` o arquivo chamando a substituição de , aumentará a alocação de memória em incrementos de *nGrowBytes*. O crescimento da alocação de memória `Attach` falhará se o bloco de memória para o que você passar não foi alocado com um método compatível com [alloc](#alloc). Para ser compatível com `Alloc`a implementação padrão de , você deve alocar a memória com a função de biblioteca em tempo de [execução malloc](../../c-runtime-library/reference/malloc.md) ou [calloc](../../c-runtime-library/reference/calloc.md).

## <a name="cmemfilecmemfile"></a><a name="cmemfile"></a>CMemFile::CMemFile

A primeira sobrecarga abre um arquivo de memória vazio.

```
CMemFile(UINT nGrowBytes = 1024);

CMemFile(
    BYTE* lpBuffer,
    UINT nBufferSize,
    UINT nGrowBytes = 0);
```

### <a name="parameters"></a>Parâmetros

*Ngrowbytes*<br/>
O incremento de alocação de memória em bytes.

*lpBuffe*r Ponteiro para um buffer que recebe informações do tamanho *nBufferSize*.

*Nbuffersize*<br/>
Um inteiro que especifica o tamanho do buffer de arquivo, em bytes.

### <a name="remarks"></a>Comentários

Observe que o arquivo é aberto pelo construtor e que você não deve chamar [CFile:::Abrir](../../mfc/reference/cfile-class.md#open).

A segunda sobrecarga age da mesma forma que se você usou o primeiro construtor e imediatamente chamado [Anexar](#attach) com os mesmos parâmetros. Para obter detalhes, consulte `Attach`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#36](../../atl-mfc-shared/reference/codesnippet/cpp/cmemfile-class_1.cpp)]

## <a name="cmemfiledetach"></a><a name="detach"></a>CMemFile::Detach

Chame esta função para obter um ponteiro `CMemFile`para o bloco de memória que está sendo usado por .

```
BYTE* Detach();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o bloco de memória que contém o conteúdo do arquivo de memória.

### <a name="remarks"></a>Comentários

Chamar essa função também `CMemFile`fecha o . Você pode reconectar o `CMemFile` bloco de memória ao ligar para [Attach](#attach). Se você quiser reanexar o arquivo e usar os dados nele, você deve chamar [CFile::GetLength](../../mfc/reference/cfile-class.md#getlength) para obter o comprimento do arquivo antes de chamar `Detach`. Observe que se você anexar `CMemFile` um bloco de memória `nGrowBytes` para que você possa usar seus dados (== 0), então você não será capaz de crescer o arquivo de memória.

## <a name="cmemfilefree"></a><a name="free"></a>CMemFile::Grátis

Esta função é `CMemFile` chamada por funções de membro.

```
virtual void Free(BYTE* lpMem);
```

### <a name="parameters"></a>Parâmetros

*LpMem*<br/>
Ponteiro para a memória a ser desalocada.

### <a name="remarks"></a>Comentários

Anular esta função para implementar a desalocação personalizada da memória. Se você substituir esta função, você provavelmente vai querer substituir [Alloc](#alloc) e [Realloc](#realloc) também.

## <a name="cmemfilegrowfile"></a><a name="growfile"></a>CMemFile::GrowFile

Esta função é chamada `CMemFile` por várias das funções do membro.

```
virtual void GrowFile(SIZE_T dwNewLen);
```

### <a name="parameters"></a>Parâmetros

*dwNewLen*<br/>
Novo tamanho do arquivo de memória.

### <a name="remarks"></a>Comentários

Você pode substituí-lo se quiser `CMemFile` mudar a forma como cresce seu arquivo. A implementação padrão chama [a Realloc](#realloc) para criar um bloco existente (ou [Alloc](#alloc) para `nGrowBytes` criar um bloco de memória), alocando memória em múltiplos do valor especificado no construtor ou na chamada [Anexar.](#attach)

## <a name="cmemfilememcpy"></a><a name="memcpy"></a>CMemFile::Memcpy

Esta função é `CMemFile` chamada pelas substituições de [CFile::Read](../../mfc/reference/cfile-class.md#read) e [CFile::Write](../../mfc/reference/cfile-class.md#write) to transfer e from the memory file.

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
Ponteiro para o bloco de memória de origem.

*Nbytes*<br/>
Número de bytes a serem copiados.

### <a name="return-value"></a>Valor retornado

Uma cópia do *lpMemTarget*.

### <a name="remarks"></a>Comentários

Anular esta função se você quiser `CMemFile` mudar a maneira como faz essas cópias de memória.

## <a name="cmemfilerealloc"></a><a name="realloc"></a>CMemFile::Realloc

Esta função é `CMemFile` chamada por funções de membro.

```
virtual BYTE* Realloc(
    BYTE* lpMem,
    SIZE_T nBytes);
```

### <a name="parameters"></a>Parâmetros

*LpMem*<br/>
Um ponteiro para o bloco de memória a ser realocado.

*Nbytes*<br/>
Novo tamanho para o bloco de memória.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o bloco de memória que foi realocado (e possivelmente movido) ou NULL se a realocação falhar.

### <a name="remarks"></a>Comentários

Anular esta função para implementar a realocação de memória personalizada. Se você substituir esta função, você provavelmente vai querer substituir [Alloc](#alloc) e [Free](#free) também.

## <a name="see-also"></a>Confira também

[Classe CFile](../../mfc/reference/cfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
