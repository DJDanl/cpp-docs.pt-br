---
title: Classe CsimpleStringT
ms.date: 10/18/2018
f1_keywords:
- CSimpleStringT
- ATLSIMPSTR/ATL::CSimpleStringT
- ATLSIMPSTR/ATL::CSimpleStringT::PCXSTR
- ATLSIMPSTR/ATL::CSimpleStringT::PXSTR
- ATLSIMPSTR/ATL::CSimpleStringT::CSimpleStringT
- ATLSIMPSTR/ATL::CSimpleStringT::Append
- ATLSIMPSTR/ATL::CSimpleStringT::AppendChar
- ATLSIMPSTR/ATL::CSimpleStringT::CopyChars
- ATLSIMPSTR/ATL::CSimpleStringT::CopyCharsOverlapped
- ATLSIMPSTR/ATL::CSimpleStringT::Empty
- ATLSIMPSTR/ATL::CSimpleStringT::FreeExtra
- ATLSIMPSTR/ATL::CSimpleStringT::GetAllocLength
- ATLSIMPSTR/ATL::CSimpleStringT::GetAt
- ATLSIMPSTR/ATL::CSimpleStringT::GetBuffer
- ATLSIMPSTR/ATL::CSimpleStringT::GetBufferSetLength
- ATLSIMPSTR/ATL::CSimpleStringT::GetLength
- ATLSIMPSTR/ATL::CSimpleStringT::GetManager
- ATLSIMPSTR/ATL::CSimpleStringT::GetString
- ATLSIMPSTR/ATL::CSimpleStringT::IsEmpty
- ATLSIMPSTR/ATL::CSimpleStringT::LockBuffer
- ATLSIMPSTR/ATL::CSimpleStringT::Preallocate
- ATLSIMPSTR/ATL::CSimpleStringT::ReleaseBuffer
- ATLSIMPSTR/ATL::CSimpleStringT::ReleaseBufferSetLength
- ATLSIMPSTR/ATL::CSimpleStringT::SetAt
- ATLSIMPSTR/ATL::CSimpleStringT::SetManager
- ATLSIMPSTR/ATL::CSimpleStringT::SetString
- ATLSIMPSTR/ATL::CSimpleStringT::StringLength
- ATLSIMPSTR/ATL::CSimpleStringT::Truncate
- ATLSIMPSTR/ATL::CSimpleStringT::UnlockBuffer
helpviewer_keywords:
- shared classes, CSimpleStringT
- strings [C++], ATL class
- CSimpleStringT class
ms.assetid: 15814fcb-5b8f-4425-a97e-3b61fc9b48d8
ms.openlocfilehash: 76d418c4f063d5787209ea72e7c681013eb37801
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81747038"
---
# <a name="csimplestringt-class"></a>Classe CsimpleStringT

Esta classe representa `CSimpleStringT` um objeto.

## <a name="syntax"></a>Sintaxe

```
template <typename BaseType>
class CSimpleStringT
```

### <a name="parameters"></a>Parâmetros

*BaseType*<br/>
O tipo de caractere da classe de cordas. Um dos seguintes pode ser feito:

- **char** (para strings de caracteres ANSI).

- **wchar_t** (para strings de caracteres Unicode).

- TCHAR (para as seqüências de caracteres ANSI e Unicode).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleStringT::PCXSTR](#pcxstr)|Um ponteiro para uma seqüência constante.|
|[CSimpleStringT::PXSTR](#pxstr)|Um ponteiro para uma corda.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleStringt::CSimpleStringT](#ctor)|Constrói `CSimpleStringT` objetos de várias maneiras.|
|[Csimplestringt::~cSimplestringt](#dtor)|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleStringT::Apêndice](#append)|Anexa um `CSimpleStringT` objeto a `CSimpleStringT` um objeto existente.|
|[CSimpleStringT::Apêndice](#appendchar)|Anexa um caractere a `CSimpleStringT` um objeto existente.|
|[CSimpleStringT::CopyChars](#copychars)|Copia um caractere ou caracteres para outra seqüência.|
|[CSimpleStringT::CopyCharsSobreposto](#copycharsoverlapped)|Copia um caractere ou caractere para outra seqüência na qual os buffers se sobrepõem.|
|[CSimpleStringt::Empty](#empty)|Força uma corda para ter um comprimento de zero.|
|[Csimplestringt::FreeExtra](#freeextra)|Libera qualquer memória extra previamente alocada pelo objeto string.|
|[CSimpleStringT::GetAllocLength](#getalloclength)|Recupera o comprimento alocado `CSimpleStringT` de um objeto.|
|[Csimplestringt::getat](#getat)|Retorna o personagem em uma determinada posição.|
|[CSimpleStringT::GetBuffer](#getbuffer)|Retorna um ponteiro para `CSimpleStringT`os caracteres em um .|
|[csimpleStringt::GetBufferSetLength](#getbuffersetlength)|Retorna um ponteiro para `CSimpleStringT`os caracteres em um , truncado para o comprimento especificado.|
|[CsimpleStringt::getlength](#getlength)|Retorna o número de `CSimpleStringT` caracteres em um objeto.|
|[CSimpleStringT::GetManager](#getmanager)|Recupera o gerenciador `CSimpleStringT` de memória do objeto.|
|[CSimpleStringT::GetString](#getstring)|Recupera a seqüência de caracteres|
|[Csimplestringt::IsEmpty](#isempty)|Testa `CSimpleStringT` se um objeto não contém caracteres.|
|[CSimpleStringT::LockBuffer](#lockbuffer)|Desabilita a contagem de referências e protege a string no buffer.|
|[CSimpleStringT::Prealocar](#preallocate)|Aloca uma quantidade específica de memória para o buffer de caracteres.|
|[CSimpleStringT::Buffer de lançamento](#releasebuffer)|Libera o controle do buffer `GetBuffer`retornado por .|
|[CSimpleStringt::ReleaseBufferSetLength](#releasebuffersetlength)|Libera o controle do buffer `GetBuffer`retornado por .|
|[Csimplestringt::setat](#setat)|Define um personagem em uma determinada posição.|
|[CSimpleStringT::SetManager](#setmanager)|Define o gerenciador `CSimpleStringT` de memória de um objeto.|
|[CSimpleStringT::SetString](#setstring)|Define a seqüência de um `CSimpleStringT` objeto.|
|[csimplestringt::StringLength](#stringlength)|Retorna o número de caracteres na seqüência especificada.|
|[CSimpleStringT::Truncar](#truncate)|Trunca a seqüência para um comprimento especificado.|
|[CSimpleStringT::UnlockBuffer](#unlockbuffer)|Permite a contagem de referência e libera a string no buffer.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleStringT::operador PCXSTR](#operator_pcxstr)|Acessa diretamente caracteres armazenados em um `CSimpleStringT` objeto como uma seqüência de caracteres estilo C.|
|[CSimpleStringT::operador\[\]](#operator_at)|Retorna o caractere em uma determinada `GetAt`posição — substituição do operador para .|
|[CSimpleStringT::operador +=](#operator_add_eq)|Concatena uma nova seqüência até o final de uma seqüência existente.|
|[CSimpleStringT::operador =](#operator_eq)|Atribui um novo valor `CSimpleStringT` a um objeto.|

### <a name="remarks"></a>Comentários

`CSimpleStringT`é a classe base para as várias classes de string suportadas pelo Visual C++. Ele fornece suporte mínimo para o gerenciamento de memória do objeto de string e manipulação básica do buffer. Para obter objetos de seqüência mais avançados, consulte [Classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr.h

## <a name="csimplestringtappend"></a><a name="append"></a>CSimpleStringT::Apêndice

Anexa um `CSimpleStringT` objeto a `CSimpleStringT` um objeto existente.

### <a name="syntax"></a>Sintaxe

```cpp
void Append(const CSimpleStringT& strSrc);
void Append(PCXSTR pszSrc, int nLength);
void Append(PCXSTR pszSrc);
```

#### <a name="parameters"></a>Parâmetros

*strSrc*<br/>
O `CSimpleStringT` objeto a ser anexado.

*pszSrc*<br/>
Um ponteiro para uma seqüência contendo os caracteres a serem anexados.

*Nlength*<br/>
O número de caracteres a serem acrescentados.

### <a name="remarks"></a>Comentários

Chame este método para anexar `CSimpleStringT` um `CSimpleStringT` objeto existente a outro objeto.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::Append`.

```cpp
CSimpleString str1(pMgr), str2(pMgr);
str1.SetString(_T("Soccer is"));
str2.SetString(_T(" an elegant game"));
str1.Append(str2);
ASSERT(_tcscmp(str1, _T("Soccer is an elegant game")) == 0);
```

## <a name="csimplestringtappendchar"></a><a name="appendchar"></a>CSimpleStringT::Apêndice

Anexa um caractere a `CSimpleStringT` um objeto existente.

### <a name="syntax"></a>Sintaxe

```cpp
void AppendChar(XCHAR ch);
```

#### <a name="parameters"></a>Parâmetros

*Ch*<br/>
O personagem a ser anexado

### <a name="remarks"></a>Comentários

Chame esta função para anexar o caractere especificado `CSimpleStringT` ao final de um objeto existente.

## <a name="csimplestringtcopychars"></a><a name="copychars"></a>CSimpleStringT::CopyChars

Copia um caractere ou `CSimpleStringT` caracteres para um objeto.

### <a name="syntax"></a>Sintaxe

```
static void CopyChars(
    XCHAR* pchDest,
    const XCHAR* pchSrc,
    int nChars) throw();
```

#### <a name="parameters"></a>Parâmetros

*pchDest*<br/>
Um ponteiro para uma seqüência de caracteres.

*pchSrc*<br/>
Um ponteiro para uma seqüência contendo os caracteres a serem copiados.

*Nchars*<br/>
O número de *caracteres pchSrc* a serem copiados.

### <a name="remarks"></a>Comentários

Chame este método para copiar caracteres de *pchSrc* para a seqüência *pchDest.*

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::CopyChars`.

```cpp
CSimpleString str(_T("xxxxxxxxxxxxxxxxxxx"), 20, pMgr);
TCHAR* pszSrc = _T("Hello world!");
_tprintf_s(_T("%s\n"), str);
str.CopyChars(str.GetBuffer(), pszSrc, 12);
_tprintf_s(_T("%s\n"), str);
```

## <a name="csimplestringtcopycharsoverlapped"></a><a name="copycharsoverlapped"></a>CSimpleStringT::CopyCharsSobreposto

Copia um caractere ou `CSimpleStringT` caracteres para um objeto.

### <a name="syntax"></a>Sintaxe

```
static void CopyCharsOverlapped(
    XCHAR* pchDest,
    const XCHAR* pchSrc,
    int nChars) throw();
```

#### <a name="parameters"></a>Parâmetros

*pchDest*<br/>
Um ponteiro para uma seqüência de caracteres.

*pchSrc*<br/>
Um ponteiro para uma seqüência contendo os caracteres a serem copiados.

*Nchars*<br/>
O número de *caracteres pchSrc* a serem copiados.

### <a name="remarks"></a>Comentários

Chame este método para copiar caracteres de *pchSrc* para a seqüência *pchDest.* Ao `CopyChars` `CopyCharsOverlapped` contrário, fornece um método seguro para copiar a partir de buffers de caracteres que podem ser sobrepostos.

### <a name="example"></a>Exemplo

Veja o exemplo de [CSimpleStringT::CopyChars](#copychars)ou `CSimpleStringT::SetString` o código-fonte para (localizado em atlsimpstr.h).

## <a name="csimplestringtcsimplestringt"></a><a name="ctor"></a>CSimpleStringt::CSimpleStringT

Constrói um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
CSimpleStringT(const XCHAR* pchSrc, int nLength, IAtlStringMgr* pStringMgr);
CSimpleStringT(PCXSTR pszSrc, IAtlStringMgr* pStringMgr);
CSimpleStringT(const CSimpleStringT& strSrc);
explicit CSimpleStringT(IAtlStringMgr* pStringMgr) throw();
```

#### <a name="parameters"></a>Parâmetros

*strSrc*<br/>
Um objeto `CSimpleStringT` existente a ser `CSimpleStringT` copiado para este objeto.

*pchSrc*<br/>
Um ponteiro para uma matriz de caracteres de comprimento *nLength,* não nulo encerrado.

*pszSrc*<br/>
Uma seqüência de terminadas nula a ser copiada para este `CSimpleStringT` objeto.

*Nlength*<br/>
Uma contagem do número `pch`de caracteres em .

*pStringMgr*<br/>
Um ponteiro para o `CSimpleStringT` gerenciador de memória do objeto. Para obter `IAtlStringMgr` mais informações `CSimpleStringT`sobre e gerenciamento de memória para , consulte [Gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).

### <a name="remarks"></a>Comentários

Construa `CSimpleStringT` um novo objeto. Como os construtores copiam os dados de entrada em um novo armazenamento alocado, exceções de memória podem resultar.

### <a name="example"></a>Exemplo

O exemplo a seguir `CSimpleStringT::CSimpleStringT` demonstra o uso do **tipo** `CSimpleString`ATL . `CSimpleString`é uma especialização comumente usada `CSimpleStringT`do modelo de classe .

```cpp
CSimpleString s1(pMgr);
// Empty string
CSimpleString s2(_T("cat"), pMgr);
// From a C string literal

CSimpleString s3(s2);
// Copy constructor
CSimpleString s4(s2 + _T(" ") + s3);

// From a string expression
CSimpleString s5(_T("xxxxxx"), 6, pMgr);
// s5 = "xxxxxx"
```

## <a name="csimplestringtempty"></a><a name="empty"></a>CSimpleStringt::Empty

Faz `CSimpleStringT` deste objeto uma seqüência vazia e libera a memória conforme apropriado.

### <a name="syntax"></a>Sintaxe

```cpp
void Empty() throw();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Strings: CString Exception Cleanup](../cstring-exception-cleanup.md).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::Empty`.

```cpp
CSimpleString s(pMgr);
ASSERT(s.IsEmpty());
```

## <a name="csimplestringtfreeextra"></a><a name="freeextra"></a>Csimplestringt::FreeExtra

Libera qualquer memória extra anteriormente alocada pela string, mas não é mais necessária.

### <a name="syntax"></a>Sintaxe

```cpp
void FreeExtra();
```

### <a name="remarks"></a>Comentários

Isso deve reduzir a sobrecarga de memória consumida pelo objeto de corda. O método realoca o buffer para o comprimento exato retornado por [GetLength](#getlength).

### <a name="example"></a>Exemplo

```cpp
CAtlString basestr;
IAtlStringMgr* pMgr;

pMgr= basestr.GetManager();
ASSERT(pMgr != NULL);

// Create a CSimpleString with 28 characters
CSimpleString str(_T("Many sports are fun to play."), 28, pMgr);
_tprintf_s(_T("Alloc length is %d, String length is %d\n"),
   str.GetAllocLength(), str.GetLength());

// Assigning a smaller string won't cause CSimpleString to free its
// memory, because it assumes the string will grow again anyway.
str = _T("Soccer is best!");
_tprintf_s(_T("Alloc length is %d, String length is %d\n"),
   str.GetAllocLength(), str.GetLength());

// This call forces CSimpleString to release the extra
// memory it doesn't need.
str.FreeExtra();
_tprintf_s(_T("Alloc length is %d, String length is %d\n"),
   str.GetAllocLength(), str.GetLength());
```

### <a name="remarks"></a>Comentários

A saída deste exemplo é a seguinte:

```Output
Alloc length is 1031, String length is 1024
Alloc length is 1031, String length is 15
Alloc length is 15, String length is 15
```

## <a name="csimplestringtgetalloclength"></a><a name="getalloclength"></a>CSimpleStringT::GetAllocLength

Recupera o comprimento alocado `CSimpleStringT` de um objeto.

### <a name="syntax"></a>Sintaxe

```
int GetAllocLength() const throw();
```

### <a name="return-value"></a>Valor retornado

O número de caracteres alocados para este objeto.

### <a name="remarks"></a>Comentários

Chame este método para determinar o número `CSimpleStringT` de caracteres alocados para este objeto. Consulte [FreeExtra](#freeextra) para obter um exemplo de chamada dessa função.

## <a name="csimplestringtgetat"></a><a name="getat"></a>Csimplestringt::getat

Retorna um caractere `CSimpleStringT` de um objeto.

### <a name="syntax"></a>Sintaxe

```
XCHAR GetAt(int iChar) const;
```

#### <a name="parameters"></a>Parâmetros

*Ichar*<br/>
Índice baseado em zero do `CSimpleStringT` caractere no objeto. O parâmetro *iChar* deve ser maior ou igual a 0 e menor do que o valor devolvido por [GetLength](#getlength). Caso contrário, `GetAt` vai gerar uma exceção.

### <a name="return-value"></a>Valor retornado

Um `XCHAR` que contenha o caractere na posição especificada na seqüência de caracteres.

### <a name="remarks"></a>Comentários

Chame este método para retornar o caractere especificado pelo *iChar*. O operador de subscrito sobrecarregado **([])** `GetAt`é um alias conveniente para . O exterminador nulo é endereçado `GetAt`sem gerar uma exceção usando . No entanto, não `GetLength`é contabilizado por , e o valor devolvido é 0.

### <a name="example"></a>Exemplo

O exemplo a seguir `CSimpleStringT::GetAt`demonstra como usar .

```cpp
CSimpleString s(_T("abcdef"), pMgr);
ASSERT(s.GetAt(2) == _T('c'));
```

## <a name="csimplestringtgetbuffer"></a><a name="getbuffer"></a>CSimpleStringT::GetBuffer

Retorna um ponteiro para o `CSimpleStringT` buffer de caracteres interno para o objeto.

### <a name="syntax"></a>Sintaxe

```
PXSTR GetBuffer(int nMinBufferLength);
PXSTR GetBuffer();
```

#### <a name="parameters"></a>Parâmetros

*nMinBufferLength*<br/>
O número mínimo de caracteres que o buffer de caracteres pode conter. Este valor não inclui espaço para um exterminador nulo.

Se *nMinBufferLength* for maior que o `GetBuffer` comprimento do buffer atual, destruirá o buffer atual, substituirá-o por um buffer do tamanho solicitado e redefinirá a contagem de referência do objeto para zero. Se você já chamou [LockBuffer](#lockbuffer) neste buffer, você perderá o bloqueio de buffer.

### <a name="return-value"></a>Valor retornado

Um `PXSTR` ponteiro para o buffer de caracteres do objeto (nuterminado).

### <a name="remarks"></a>Comentários

Chame este método para retornar `CSimpleStringT` o conteúdo de buffer do objeto. O retornado `PXSTR` não é uma constante e, portanto, permite a modificação direta do `CSimpleStringT` conteúdo.

Se você usar o `GetBuffer` ponteiro retornado para alterar o conteúdo da seqüência, você deve chamar [ReleaseBuffer](#releasebuffer) antes de usar quaisquer outros `CSimpleStringT` métodos de membro.

O endereço `GetBuffer` retornado pode não ser `ReleaseBuffer` válido `CSimpleStringT` após a `CSimpleStringT` chamada, pois operações adicionais podem fazer com que o buffer seja realocado. O buffer não é realocado se você não `CSimpleStringT`alterar o comprimento do .

A memória tampão é `CSimpleStringT` automaticamente liberada quando o objeto é destruído.

Se você mesmo acompanhar o comprimento da seqüência, você não deve anexar o caractere nulo final. No entanto, você deve especificar o `ReleaseBuffer`comprimento final da seqüência quando você liberar o buffer com . Se você anexar um caractere nulo terminando, você deve passar -1 (o padrão) para o comprimento. `ReleaseBuffer`em seguida, determina o comprimento do buffer.

Se houver memória insuficiente `GetBuffer` para satisfazer a solicitação, este método lançará uma CMemoryException*.

### <a name="example"></a>Exemplo

```cpp
CSimpleString s(_T("abcd"), pMgr);
LPTSTR pBuffer = s.GetBuffer(10);
int sizeOfBuffer = s.GetAllocLength();

// Directly access CSimpleString buffer
_tcscpy_s(pBuffer, sizeOfBuffer, _T("Hello"));
ASSERT(_tcscmp(s, _T("Hello")) == 0);
s.ReleaseBuffer();
```

## <a name="csimplestringtgetbuffersetlength"></a><a name="getbuffersetlength"></a>csimpleStringt::GetBufferSetLength

Retorna um ponteiro para o `CSimpleStringT` buffer de caracteres interno para o objeto, truncando ou aumentando seu comprimento, se necessário, para exatamente corresponder ao comprimento especificado em *nLength*.

### <a name="syntax"></a>Sintaxe

```
PXSTR GetBufferSetLength(int nLength);
```

#### <a name="parameters"></a>Parâmetros

*Nlength*<br/>
O tamanho exato `CSimpleStringT` do buffer de caracteres nos caracteres.

### <a name="return-value"></a>Valor retornado

Um `PXSTR` ponteiro para o buffer de caracteres do objeto (nuterminado).

### <a name="remarks"></a>Comentários

Chame este método para recuperar um comprimento especificado do buffer interno do `CSimpleStringT` objeto. O ponteiro `PXSTR` retornado não é **const** `CSimpleStringT` e, portanto, permite a modificação direta do conteúdo.

Se você usar o ponteiro retornado por [GetBufferSetLength](#getbuffersetlength) para alterar o conteúdo da seqüência, ligue `ReleaseBuffer` para atualizar o estado interno antes de `CsimpleStringT` usar quaisquer outros `CSimpleStringT` métodos.

O endereço `GetBufferSetLength` retornado pode não ser `ReleaseBuffer` válido `CSimpleStringT` após a `CSimpleStringT` chamada, pois operações adicionais podem fazer com que o buffer seja realocado. O buffer não é reatribuído se você não `CSimpleStringT`alterar o comprimento do .

A memória tampão é `CSimpleStringT` automaticamente liberada quando o objeto é destruído.

Se você mesmo acompanhar o comprimento da corda, não apene o caractere nulo final. Você deve especificar o comprimento final da `ReleaseBuffer`seqüência quando você liberar o buffer usando . Se você anexar um caractere nulo `ReleaseBuffer`terminando quando chamar, passe -1 `ReleaseBuffer`(o padrão) para o comprimento para , e `ReleaseBuffer` executará um `strlen` no buffer para determinar seu comprimento.

Para obter mais informações sobre contagem de referências, consulte os seguintes artigos:

- [Gerenciamento de vidas de objetos através](/windows/win32/com/managing-object-lifetimes-through-reference-counting) da contagem de referência sdk do Windows.

- [Implementando contagem de referência](/windows/win32/com/implementing-reference-counting) sdk do Windows.

- [Regras para gerenciar contagens de referência](/windows/win32/com/rules-for-managing-reference-counts) no Windows SDK.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::GetBufferSetLength`.

```cpp
CSimpleString str(pMgr);
LPTSTR pstr = str.GetBufferSetLength(3);
pstr[0] = _T('C');
pstr[1] = _T('u');
pstr[2] = _T('p');

// No need for trailing zero or call to ReleaseBuffer()
// because GetBufferSetLength() set it for us.

str += _T(" soccer is best!");
ASSERT(_tcscmp(str, _T("Cup soccer is best!")) == 0);
```

## <a name="csimplestringtgetlength"></a><a name="getlength"></a>CsimpleStringt::getlength

Retorna o número de `CSimpleStringT` caracteres no objeto.

### <a name="syntax"></a>Sintaxe

```
int GetLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Uma contagem dos personagens na seqüência.

### <a name="remarks"></a>Comentários

Chame este método para retornar o número de caracteres no objeto. A contagem não inclui um exterminador nulo.

Para conjuntos de caracteres multibytes (MBCS), `GetLength` conta cada caractere de 8 bits; ou seja, um byte de chumbo e trilha em um caractere multibyte são contados como dois bytes. Consulte [FreeExtra](#freeextra) para obter um exemplo de chamada dessa função.

## <a name="csimplestringtgetmanager"></a><a name="getmanager"></a>CSimpleStringT::GetManager

Recupera o gerenciador `CSimpleStringT` de memória do objeto.

### <a name="syntax"></a>Sintaxe

```
IAtlStringMgr* GetManager() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `CSimpleStringT` gerenciador de memória para o objeto.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o `CSimpleStringT` gerenciador de memória usado pelo objeto. Para obter mais informações sobre gerenciadores de memória e objetos de string, consulte [Gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).

## <a name="csimplestringtgetstring"></a><a name="getstring"></a>CSimpleStringT::GetString

Recupera a seqüência de caracteres.

### <a name="syntax"></a>Sintaxe

```
PCXSTR GetString() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma seqüência de caracteres com término nulo.

### <a name="remarks"></a>Comentários

Chame este método para recuperar a `CSimpleStringT` seqüência de caracteres associada ao objeto.

> [!NOTE]
> O ponteiro `PCXSTR` retornado é **const** e `CSimpleStringT` não permite modificação direta do conteúdo.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::GetString`.

```cpp
CSimpleString str(pMgr);
str += _T("Cup soccer is best!");
_tprintf_s(_T("%s"), str.GetString());
```

## <a name="csimplestringtisempty"></a><a name="isempty"></a>Csimplestringt::IsEmpty

Testa `CSimpleStringT` um objeto para a condição vazia.

### <a name="syntax"></a>Sintaxe

```
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE `CSimpleStringT` se o objeto tiver 0 comprimento; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame este método para determinar se o objeto contém uma seqüência de string vazia.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::IsEmpty`.

```cpp
CSimpleString s(pMgr);
ASSERT(s.IsEmpty());
```

## <a name="csimplestringtlockbuffer"></a><a name="lockbuffer"></a>CSimpleStringT::LockBuffer

Desabilita a contagem de referências e protege a string no buffer.

### <a name="syntax"></a>Sintaxe

```
PXSTR LockBuffer();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `CSimpleStringT` para um objeto ou uma seqüência de terminadas por nulo.

### <a name="remarks"></a>Comentários

Chame este método para bloquear `CSimpleStringT` o buffer do objeto. Ao `LockBuffer`ligar, você cria uma cópia da string, com um -1 para a contagem de referência. Quando o valor da contagem de referência é -1, a seqüência no buffer é considerada em um estado "bloqueado". Enquanto estiver em um estado bloqueado, a string é protegida de duas maneiras:

- Nenhuma outra seqüência pode obter uma referência aos dados na seqüência bloqueada, mesmo que essa seqüência seja atribuída à string bloqueada.

- A seqüência bloqueada nunca fará referência a outra seqüência, mesmo que essa outra seqüência seja copiada para a seqüência bloqueada.

Ao bloquear a seqüência no buffer, certifique-se de que a retida exclusiva da corda no buffer permanecerá intacta.

Depois de terminar `LockBuffer`com , ligue [UnlockBuffer](#unlockbuffer) para redefinir a contagem de referência para 1.

> [!NOTE]
> Se você chamar [GetBuffer](#getbuffer) em um `GetBuffer` buffer `nMinBufferLength` bloqueado e definir o parâmetro para maior do que o comprimento do buffer atual, você perderá o bloqueio de buffer. Tal chamada `GetBuffer` para destruir o buffer atual, substitui-o por um buffer do tamanho solicitado e redefine a contagem de referência para zero.

Para obter mais informações sobre contagem de referências, consulte os seguintes artigos:

- [Gerenciamento de vidas de objetos através](/windows/win32/com/managing-object-lifetimes-through-reference-counting) da contagem de referência sdk do Windows

- [Implementando contagem de referência](/windows/win32/com/implementing-reference-counting) no SDK do Windows

- [Regras para gerenciar contagens de referência](/windows/win32/com/rules-for-managing-reference-counts) no Windows SDK

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::LockBuffer`.

```cpp
CSimpleString str(_T("Hello"), pMgr);
TCHAR ch;

str.LockBuffer();
ch = str.GetAt(2);
_tprintf_s(_T("%c"), ch);
str.UnlockBuffer();
```

## <a name="csimplestringtoperator"></a><a name="operator_at"></a>CSimpleStringT::operador\[\]

Chame esta função para acessar um único caractere da matriz de caracteres.

### <a name="syntax"></a>Sintaxe

```
XCHAR operator[](int iChar) const;
```

#### <a name="parameters"></a>Parâmetros

*Ichar*<br/>
Índice baseado em zero de um caractere na seqüência.

### <a name="remarks"></a>Comentários

O operador de subscrição sobrecarregado **([]** retorna um único caractere especificado pelo índice baseado em zero no *iChar*. Este operador é um substituto conveniente para a função [getat](#getat) membro.

> [!NOTE]
> Você pode usar o operador de subscrito **([]** para `CSimpleStringT`obter o valor de um caractere em `CSimpleStringT`um , mas você não pode usá-lo para alterar o valor de um caractere em um .

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::operator []`.

```cpp
CSimpleString s(_T("abc"), pMgr);
ASSERT(s[1] == _T('b'));
```

## <a name="csimplestringtoperator-"></a><a name="operator_at"></a>CSimpleStringT::operador\[\]

Chame esta função para acessar um único caractere da matriz de caracteres.

### <a name="syntax"></a>Sintaxe

```
XCHAR operator[](int iChar) const;
```

### <a name="parameters"></a>Parâmetros

*Ichar*<br/>
Índice baseado em zero de um caractere na seqüência.

### <a name="remarks"></a>Comentários

O operador de subscrição sobrecarregado **([]** retorna um único caractere especificado pelo índice baseado em zero no *iChar*. Este operador é um substituto conveniente para a função [getat](#getat) membro.

> [!NOTE]
> Você pode usar o operador de subscrito **([]** para `CSimpleStringT`obter o valor de um caractere em `CSimpleStringT`um , mas você não pode usá-lo para alterar o valor de um caractere em um .

## <a name="csimplestringtoperator-"></a><a name="operator_add_eq"></a>CSimpleStringT::operador +=

Junta-se a uma nova seqüência ou caractere ao final de uma seqüência existente.

### <a name="syntax"></a>Sintaxe

```
CSimpleStringT& operator +=(PCXSTR pszSrc);
CSimpleStringT& operator +=(const CSimpleStringT& strSrc);
template<int t_nSize>
CSimpleStringT& operator+=(const CStaticString< XCHAR, t_nSize >& strSrc);
CSimpleStringT& operator +=(char ch);
CSimpleStringT& operator +=(unsigned char ch);
CSimpleStringT& operator +=(wchar_t ch);
```

#### <a name="parameters"></a>Parâmetros

*pszSrc*<br/>
Um ponteiro para uma seqüência de terminadas nula.

*strSrc*<br/>
Um ponteiro para `CSimpleStringT` um objeto existente.

*Ch*<br/>
O caractere a ser acrescentado.

### <a name="remarks"></a>Comentários

O operador aceita `CSimpleStringT` outro objeto ou um personagem. Observe que exceções de memória podem ocorrer sempre que você usar este operador `CSimpleStringT` de concatenação porque o novo armazenamento pode ser alocado para caracteres adicionados a este objeto.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::operator +=`.

```cpp
CSimpleString str(_T("abc"), pMgr);
ASSERT(_tcscmp((str += _T("def")), _T("abcdef")) == 0);
```

## <a name="csimplestringtoperator-"></a><a name="operator_eq"></a>CSimpleStringT::operador =

Atribui um novo valor `CSimpleStringT` a um objeto.

### <a name="syntax"></a>Sintaxe

```
CSimpleStringT& operator =(PCXSTR pszSrc);
CSimpleStringT& operator =(const CSimpleStringT& strSrc);
```

#### <a name="parameters"></a>Parâmetros

*pszSrc*<br/>
Um ponteiro para uma seqüência de terminadas nula.

*strSrc*<br/>
Um ponteiro para `CSimpleStringT` um objeto existente.

### <a name="remarks"></a>Comentários

Se a string destino (o lado esquerdo) já for grande o suficiente para armazenar os novos dados, nenhuma nova alocação de memória será realizada. Observe que exceções de memória podem ocorrer sempre que você usar o `CSimpleStringT` operador de atribuição porque o novo armazenamento é frequentemente alocado para segurar o objeto resultante.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::operator =`.

```cpp
CSimpleString s1(pMgr), s2(pMgr);
// Empty CSimpleStringT objects

s1 = _T("cat");
// s1 = "cat"
ASSERT(_tcscmp(s1, _T("cat")) == 0);

s2 = s1;               // s1 and s2 each = "cat"
ASSERT(_tcscmp(s2, _T("cat")) == 0);

s1 = _T("the ") + s1;
// Or expressions
ASSERT(_tcscmp(s1, _T("the cat")) == 0);

s1 = _T("x");
// Or just individual characters
ASSERT(_tcscmp(s1, _T("x")) == 0);
```

## <a name="csimplestringtoperator-pcxstr"></a><a name="operator_pcxstr"></a>CSimpleStringT::operador PCXSTR

Acessa diretamente caracteres armazenados em um `CSimpleStringT` objeto como uma seqüência de caracteres estilo C.

### <a name="syntax"></a>Sintaxe

```
operator PCXSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro de caracteres para os dados da seqüência.

### <a name="remarks"></a>Comentários

Nenhum caractere é copiado; apenas um ponteiro é devolvido. Tenha cuidado com este operador. Se você `CString` alterar um objeto depois de ter obtido o ponteiro do caractere, você pode causar uma realocação de memória que invalida o ponteiro.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::operator PCXSTR`.

```cpp
// If the prototype of a function is known to the compiler,
// the PCXSTR cast operator may be invoked implicitly.

CSimpleString strSports(L"Soccer is Best!", pMgr);
WCHAR sz[1024];

wcscpy_s(sz, strSports);

// If the prototype isn't known or is a va_arg prototype,
// you must invoke the cast operator explicitly. For example,
// the va_arg part of a call to swprintf_s() needs the cast:

swprintf_s(sz, 1024, L"I think that %s!\n", (PCWSTR)strSports);

// While the format parameter is known to be an PCXSTR and
// therefore doesn't need the cast:

swprintf_s(sz, 1024, strSports);

// Note that some situations are ambiguous. This line will
// put the address of the strSports object to stdout:

wcout << strSports;

// while this line will put the content of the string out:

wcout << (PCWSTR)strSports;
```

## <a name="csimplestringtpcxstr"></a><a name="pcxstr"></a>CSimpleStringT::PCXSTR

Um ponteiro para uma seqüência constante.

### <a name="syntax"></a>Sintaxe

```
typedef ChTraitsBase< BaseType >::PCXSTR PCXSTR;
```

## <a name="csimplestringtpreallocate"></a><a name="preallocate"></a>CSimpleStringT::Prealocar

Aloca uma quantidade específica de bytes para o `CSimpleStringT` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
void Preallocate( int nLength);
```

#### <a name="parameters"></a>Parâmetros

*Nlength*<br/>
O tamanho exato `CSimpleStringT` do buffer de caracteres nos caracteres.

### <a name="remarks"></a>Comentários

Chame este método para alocar `CSimpleStringT` um tamanho de buffer específico para o objeto.

`CSimpleStringT`gera uma exceção STATUS_NO_MEMORY se não puder alocar espaço para o buffer de caracteres. Por padrão, a alocação de memória é `HeapAlloc` `HeapReAlloc`executada por funções de API WIN32 ou .

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::Preallocate`.

```cpp
CSimpleString str(pMgr);
_tprintf_s(_T("Allocated length: %d\n"), str.GetAllocLength());
str.Preallocate(100);
_tprintf_s(_T("Allocated length: %d\n"), str.GetAllocLength());
```

## <a name="csimplestringtpxstr"></a><a name="pxstr"></a>CSimpleStringT::PXSTR

Um ponteiro para uma corda.

### <a name="syntax"></a>Sintaxe

```
typedef ChTraitsBase< BaseType >::PXSTR PXSTR;
```

## <a name="csimplestringtreleasebuffer"></a><a name="releasebuffer"></a>CSimpleStringT::Buffer de lançamento

Libera o controle do buffer alocado pelo [GetBuffer](#getbuffer).

### <a name="syntax"></a>Sintaxe

```cpp
void ReleaseBuffer(int nNewLength = -1);
```

#### <a name="parameters"></a>Parâmetros

*nNewLength*<br/>
O novo comprimento da seqüência nos personagens, sem contar um exterminador nulo. Se a seqüência for anulada, o `CSimpleStringT` valor padrão -1 definirá o tamanho para o comprimento atual da string.

### <a name="remarks"></a>Comentários

Chame este método para realocar ou liberar o buffer do objeto de seqüência. Se você sabe que a seqüência no buffer é nula, você pode omiti-lo o argumento *nNewLength.* Se a seqüência não for nula, use *nNewLength* para especificar seu comprimento. O endereço retornado pelo [GetBuffer](#getbuffer) é `ReleaseBuffer` inválido `CSimpleStringT` após a chamada ou qualquer outra operação.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::ReleaseBuffer`.

```cpp
const int bufferSize = 1024;
CSimpleString s(_T("abc"), pMgr);
LPTSTR p = s.GetBuffer(bufferSize);
_tcscpy_s(p, bufferSize, _T("abc"));

// use the buffer directly
ASSERT(s.GetLength() == 3);

// String length = 3
s.ReleaseBuffer();

// Surplus memory released, p is now invalid.
ASSERT(s.GetLength() == 3);

// Length still 3
```

## <a name="csimplestringtreleasebuffersetlength"></a><a name="releasebuffersetlength"></a>CSimpleStringt::ReleaseBufferSetLength

Libera o controle do buffer alocado pelo [GetBuffer](#getbuffer).

### <a name="syntax"></a>Sintaxe

```cpp
void ReleaseBufferSetLength(int nNewLength);
```

#### <a name="parameters"></a>Parâmetros

*nNewLength*<br/>
O comprimento da corda sendo lançado

### <a name="remarks"></a>Comentários

Esta função é funcionalmente semelhante ao [ReleaseBuffer,](#releasebuffer) exceto que um comprimento válido para o objeto de seqüência deve ser passado.

## <a name="csimplestringtsetat"></a><a name="setat"></a>Csimplestringt::setat

Define um único `CSimpleStringT` caractere de um objeto.

### <a name="syntax"></a>Sintaxe

```cpp
void SetAt(int iChar, XCHAR ch);
```

#### <a name="parameters"></a>Parâmetros

*Ichar*<br/>
Índice baseado em zero do `CSimpleStringT` caractere no objeto. O parâmetro *iChar* deve ser maior ou igual a 0 e menor do que o valor devolvido por [GetLength](#getlength).

*Ch*<br/>
O novo personagem.

### <a name="remarks"></a>Comentários

Chame este método para substituir o caractere localizado no *iChar*. Este método não ampliará a seqüência se *o iChar* exceder os limites da seqüência existente.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::SetAt`.

```cpp
CSimpleString s(_T("abcdef"), pMgr);
s.SetAt(1, _T('a'));
ASSERT(_tcscmp(s, _T("aacdef")) == 0);
```

## <a name="csimplestringtsetmanager"></a><a name="setmanager"></a>CSimpleStringT::SetManager

Especifica o gerenciador `CSimpleStringT` de memória do objeto.

### <a name="syntax"></a>Sintaxe

```cpp
void SetManager(IAtlStringMgr* pStringMgr);
```

#### <a name="parameters"></a>Parâmetros

*pStringMgr*<br/>
Um ponteiro para o novo gerenciador de memória.

### <a name="remarks"></a>Comentários

Chame este método para especificar um `CSimpleStringT` novo gerenciador de memória usado pelo objeto. Para obter mais informações sobre gerenciadores de memória e objetos de string, consulte [Gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::SetManager`.

```cpp
CSimpleString s(pMgr);
s.SetManager(pCustomMgr);
```

## <a name="csimplestringtsetstring"></a><a name="setstring"></a>CSimpleStringT::SetString

Define a seqüência de um `CSimpleStringT` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
void SetString(PCXSTR pszSrc, int nLength);
void SetString(PCXSTR pszSrc);
```

#### <a name="parameters"></a>Parâmetros

*pszSrc*<br/>
Um ponteiro para uma seqüência de terminadas nula.

*Nlength*<br/>
Uma contagem do número de caracteres em *pszSrc*.

### <a name="remarks"></a>Comentários

Copie uma corda `CSimpleStringT` no objeto. `SetString`substitui os dados de seqüência mais antigos no buffer.

Ambas as `SetString` versões de verificar se *pszSrc* é um ponteiro nulo e, se for, jogue um erro E_INVALIDARG.

A versão de um `SetString` parâmetro espera que *pszSrc* aponte para uma seqüência de terminadas por nulo.

A versão de dois `SetString` parâmetros também espera que *pszSrc* seja uma seqüência de terminais nula. Ele usa *nLength* como o comprimento da seqüência, a menos que encontre um exterminador nulo primeiro.

A versão de dois `SetString` parâmetros também verifica se *pszSrc* aponta `CSimpleStringT`para um local no buffer atual em . Neste caso especial, `SetString` usa uma função de cópia de memória que não sobreescreve os dados da seqüência de strings à medida que copia os dados da seqüência de volta ao seu buffer.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::SetString`.

```cpp
CSimpleString s(_T("abcdef"), pMgr);
ASSERT(_tcscmp(s, _T("abcdef")) == 0);
s.SetString(_T("Soccer"), 6);
ASSERT(_tcscmp(s, _T("Soccer")) == 0);
```

## <a name="csimplestringtstringlength"></a><a name="stringlength"></a>csimplestringt::StringLength

Retorna o número de caracteres na seqüência especificada.

### <a name="syntax"></a>Sintaxe

```
ATL_NOINLINE static int StringLength(PCXSTR psz) throw();
```

#### <a name="parameters"></a>Parâmetros

*Psz*<br/>
Um ponteiro para uma seqüência de terminadas nula.

### <a name="return-value"></a>Valor retornado

O número de caracteres em *psz;* sem contar um exterminador nulo.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o número de caracteres na seqüência apontada pelo *psz*.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::StringLength`.

```cpp
ASSERT(CSimpleString::StringLength(_T("soccer")) == 6);
```

## <a name="csimplestringttruncate"></a><a name="truncate"></a>CSimpleStringT::Truncar

Trunca a corda para o novo comprimento.

### <a name="syntax"></a>Sintaxe

```cpp
void Truncate(int nNewLength);
```

#### <a name="parameters"></a>Parâmetros

*nNewLength*<br/>
O novo comprimento da corda.

### <a name="remarks"></a>Comentários

Chame este método para truncar o conteúdo da seqüência para o novo comprimento.

> [!NOTE]
> Isso não afeta o comprimento alocado do buffer. Para diminuir ou aumentar o buffer atual, consulte [FreeExtra](#freeextra) e [Preallocate](#preallocate).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso de `CSimpleStringT::Truncate`.

```cpp
CSimpleString str(_T("abcdefghi"), pMgr);
_tprintf_s(_T("Allocated length: %d\n"), str.GetLength());
_tprintf_s(_T("Contents: %s\n"), str);
str.Truncate(4);
_tprintf_s(_T("Allocated length: %d\n"), str.GetLength());
_tprintf_s(_T("Contents: %s\n"), str);
```

## <a name="csimplestringtunlockbuffer"></a><a name="unlockbuffer"></a>CSimpleStringT::UnlockBuffer

Desbloqueia o `CSimpleStringT` buffer do objeto.

### <a name="syntax"></a>Sintaxe

```cpp
void UnlockBuffer() throw();
```

### <a name="remarks"></a>Comentários

Chame este método para redefinir a contagem de referência da string para 1.

O `CSimpleStringT` destruidor liga `UnlockBuffer` automaticamente para garantir que o buffer não esteja bloqueado quando o destruidor é chamado. Para um exemplo deste método, consulte [LockBuffer](#lockbuffer).

## <a name="csimplestringtcsimplestringt"></a><a name="dtor"></a>Csimplestringt::~cSimplestringt

Destrói um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
~CSimpleStringT() throw();
```

### <a name="remarks"></a>Comentários

Chame este método `CSimpleStringT` para destruir o objeto.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
