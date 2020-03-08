---
title: Classe CSimpleStringT
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
ms.openlocfilehash: c033346b7a687a1c6778ad23e30ee0e73c787ad8
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78865064"
---
# <a name="csimplestringt-class"></a>Classe CSimpleStringT

Essa classe representa um objeto `CSimpleStringT`.

## <a name="syntax"></a>Sintaxe

```
template <typename BaseType>
class CSimpleStringT
```

### <a name="parameters"></a>Parâmetros

*BaseType*<br/>
O tipo de caractere da classe de cadeia de caracteres. Pode ser um dos seguintes:

- **Char** (para cadeias de caracteres ANSI).

- **wchar_t** (para cadeias de caracteres Unicode).

- TCHAR (para cadeias de caracteres ANSI e Unicode).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSimpleStringT::P CXSTR](#pcxstr)|Um ponteiro para uma cadeia de caracteres constante.|
|[CSimpleStringT::P XSTR](#pxstr)|Um ponteiro para uma cadeia de caracteres.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSimpleStringT::CSimpleStringT](#ctor)|Constrói `CSimpleStringT` objetos de várias maneiras.|
|[CSimpleStringT:: ~ CSimpleStringT](#dtor)|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CSimpleStringT:: Append](#append)|Anexa um objeto `CSimpleStringT` a um objeto `CSimpleStringT` existente.|
|[CSimpleStringT::AppendChar](#appendchar)|Anexa um caractere a um objeto `CSimpleStringT` existente.|
|[CSimpleStringT::CopyChars](#copychars)|Copia um caractere ou caracteres para outra cadeia de caracteres.|
|[CSimpleStringT::CopyCharsOverlapped](#copycharsoverlapped)|Copia um caractere ou caracteres para outra cadeia de caracteres na qual os buffers se sobrepõem.|
|[CSimpleStringT:: Empty](#empty)|Força uma cadeia de caracteres a ter um comprimento igual a zero.|
|[CSimpleStringT::FreeExtra](#freeextra)|Libera qualquer memória extra alocada anteriormente pelo objeto de cadeia de caracteres.|
|[CSimpleStringT::GetAllocLength](#getalloclength)|Recupera o comprimento alocado de um objeto `CSimpleStringT`.|
|[CSimpleStringT::GetAt](#getat)|Retorna o caractere em uma determinada posição.|
|[CSimpleStringT::GetBuffer](#getbuffer)|Retorna um ponteiro para os caracteres em um `CSimpleStringT`.|
|[CSimpleStringT::GetBufferSetLength](#getbuffersetlength)|Retorna um ponteiro para os caracteres em um `CSimpleStringT`, truncando para o comprimento especificado.|
|[CSimpleStringT::GetLength](#getlength)|Retorna o número de caracteres em um objeto `CSimpleStringT`.|
|[CSimpleStringT:: GetManager](#getmanager)|Recupera o Gerenciador de memória do objeto `CSimpleStringT`.|
|[CSimpleStringT:: GetString](#getstring)|Recupera a cadeia de caracteres|
|[CSimpleStringT:: IsEmpty](#isempty)|Testa se um objeto de `CSimpleStringT` não contém caracteres.|
|[CSimpleStringT::LockBuffer](#lockbuffer)|Desabilita a contagem de referência e protege a cadeia de caracteres no buffer.|
|[CSimpleStringT::P realocar](#preallocate)|Aloca uma quantidade específica de memória para o buffer de caracteres.|
|[CSimpleStringT::ReleaseBuffer](#releasebuffer)|Libera o controle do buffer retornado por `GetBuffer`.|
|[CSimpleStringT::ReleaseBufferSetLength](#releasebuffersetlength)|Libera o controle do buffer retornado por `GetBuffer`.|
|[CSimpleStringT::SetAt](#setat)|Define um caractere em uma determinada posição.|
|[CSimpleStringT:: SetManager](#setmanager)|Define o Gerenciador de memória de um objeto `CSimpleStringT`.|
|[CSimpleStringT:: SetString](#setstring)|Define a cadeia de caracteres de um objeto `CSimpleStringT`.|
|[CSimpleStringT::StringLength](#stringlength)|Retorna o número de caracteres na cadeia de caracteres especificada.|
|[CSimpleStringT:: TRUNCATE](#truncate)|Trunca a cadeia de caracteres para um comprimento especificado.|
|[CSimpleStringT::UnlockBuffer](#unlockbuffer)|Habilita a contagem de referência e libera a cadeia de caracteres no buffer.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Operador CSimpleStringT:: Operator PCXSTR](#operator_pcxstr)|Acessa diretamente os caracteres armazenados em um objeto `CSimpleStringT` como uma cadeia de estilo C.|
|[CSimpleStringT:: Operator\[\]](#operator_at)|Retorna o caractere em uma determinada posição — substituição de operador para `GetAt`.|
|[CSimpleStringT:: Operator + =](#operator_add_eq)|Concatena uma nova cadeia de caracteres ao final de uma cadeia de caracteres existente.|
|[CSimpleStringT:: Operator =](#operator_eq)|Atribui um novo valor a um objeto `CSimpleStringT`.|

### <a name="remarks"></a>Comentários

`CSimpleStringT` é a classe base para as várias classes de cadeia de caracteres C++com suporte no Visual. Ele fornece suporte mínimo para o gerenciamento de memória do objeto de cadeia de caracteres e a manipulação básica de buffer. Para objetos de cadeia de caracteres mais avançados, consulte [classe CStringT](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlsimpstr. h

## <a name="append"></a>CSimpleStringT:: Append

Anexa um objeto `CSimpleStringT` a um objeto `CSimpleStringT` existente.

### <a name="syntax"></a>Sintaxe

```
void Append(const CSimpleStringT& strSrc);
void Append(PCXSTR pszSrc, int nLength);
void Append(PCXSTR pszSrc);
```

#### <a name="parameters"></a>Parâmetros

*strSrc*<br/>
O objeto `CSimpleStringT` a ser anexado.

*pszSrc*<br/>
Um ponteiro para uma cadeia que contém os caracteres a serem acrescentados.

*nLength*<br/>
O número de caracteres a serem acrescentados.

### <a name="remarks"></a>Comentários

Chame esse método para acrescentar um objeto de `CSimpleStringT` existente a outro objeto `CSimpleStringT`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::Append`.

```cpp
CSimpleString str1(pMgr), str2(pMgr);
str1.SetString(_T("Soccer is"));
str2.SetString(_T(" an elegant game"));
str1.Append(str2);
ASSERT(_tcscmp(str1, _T("Soccer is an elegant game")) == 0);
```

##  <a name="appendchar"></a>CSimpleStringT::AppendChar

Anexa um caractere a um objeto `CSimpleStringT` existente.

### <a name="syntax"></a>Sintaxe

```
void AppendChar(XCHAR ch);
```

#### <a name="parameters"></a>Parâmetros

*CH*<br/>
O caractere a ser anexado

### <a name="remarks"></a>Comentários

Chame essa função para acrescentar o caractere especificado ao final de um objeto de `CSimpleStringT` existente.

##  <a name="copychars"></a>CSimpleStringT::CopyChars

Copia um ou mais caracteres para um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
static void CopyChars(
    XCHAR* pchDest,
    const XCHAR* pchSrc,
    int nChars) throw();
```

#### <a name="parameters"></a>Parâmetros

*pchDest*<br/>
Um ponteiro para uma cadeia de caracteres.

*pchSrc*<br/>
Um ponteiro para uma cadeia que contém os caracteres a serem copiados.

*nChars*<br/>
O número de caracteres *pchSrc* a serem copiados.

### <a name="remarks"></a>Comentários

Chame esse método para copiar os caracteres de *pchSrc* para a cadeia de caracteres *pchDest* .

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::CopyChars`.

```cpp
CSimpleString str(_T("xxxxxxxxxxxxxxxxxxx"), 20, pMgr);
TCHAR* pszSrc = _T("Hello world!");
_tprintf_s(_T("%s\n"), str);
str.CopyChars(str.GetBuffer(), pszSrc, 12);
_tprintf_s(_T("%s\n"), str);
```

##  <a name="copycharsoverlapped"></a>CSimpleStringT::CopyCharsOverlapped

Copia um ou mais caracteres para um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
static void CopyCharsOverlapped(
    XCHAR* pchDest,
    const XCHAR* pchSrc,
    int nChars) throw();
```

#### <a name="parameters"></a>Parâmetros

*pchDest*<br/>
Um ponteiro para uma cadeia de caracteres.

*pchSrc*<br/>
Um ponteiro para uma cadeia que contém os caracteres a serem copiados.

*nChars*<br/>
O número de caracteres *pchSrc* a serem copiados.

### <a name="remarks"></a>Comentários

Chame esse método para copiar os caracteres de *pchSrc* para a cadeia de caracteres *pchDest* . Ao contrário de `CopyChars`, `CopyCharsOverlapped` fornece um método seguro para copiar de buffers de caracteres que podem ser sobrepostos.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [CSimpleStringT:: CopyChars](#copychars)ou o código-fonte para `CSimpleStringT::SetString` (localizado em atlsimpstr. h).

##  <a name="ctor"></a>CSimpleStringT::CSimpleStringT

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
Um objeto de `CSimpleStringT` existente a ser copiado para este objeto `CSimpleStringT`.

*pchSrc*<br/>
Um ponteiro para uma matriz de caracteres de comprimento *nLength*, não termina com NULL.

*pszSrc*<br/>
Uma cadeia de caracteres terminada em nulo a ser copiada para este `CSimpleStringT` objeto.

*nLength*<br/>
Uma contagem do número de caracteres em `pch`.

*pStringMgr*<br/>
Um ponteiro para o Gerenciador de memória do objeto `CSimpleStringT`. Para obter mais informações sobre `IAtlStringMgr` e gerenciamento de memória para `CSimpleStringT`, consulte [Gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).

### <a name="remarks"></a>Comentários

Construa um novo objeto `CSimpleStringT`. Como os construtores copiam os dados de entrada para o novo armazenamento alocado, as exceções de memória podem resultar.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::CSimpleStringT` usando o **typedef** do ATL `CSimpleString`. `CSimpleString` é uma especialização comumente usada do modelo de classe `CSimpleStringT`.

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

##  <a name="empty"></a>CSimpleStringT:: Empty

Torna esse `CSimpleStringT` objeto uma cadeia de caracteres vazia e libera a memória conforme apropriado.

### <a name="syntax"></a>Sintaxe

```
void Empty() throw();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [cadeias de caracteres: limpeza de exceção CString](../cstring-exception-cleanup.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::Empty`.

```cpp
CSimpleString s(pMgr);
ASSERT(s.IsEmpty());
```

##  <a name="freeextra"></a>CSimpleStringT::FreeExtra

Libera qualquer memória extra alocada anteriormente pela cadeia de caracteres, mas não é mais necessária.

### <a name="syntax"></a>Sintaxe

```
void FreeExtra();
```

### <a name="remarks"></a>Comentários

Isso deve reduzir a sobrecarga de memória consumida pelo objeto de cadeia de caracteres. O método realoca o buffer para o tamanho exato retornado por [GetLength](#getlength).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

##  <a name="getalloclength"></a>CSimpleStringT::GetAllocLength

Recupera o comprimento alocado de um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
int GetAllocLength() const throw();
```

### <a name="return-value"></a>Valor retornado

O número de caracteres alocados para este objeto.

### <a name="remarks"></a>Comentários

Chame esse método para determinar o número de caracteres alocados para este `CSimpleStringT` objeto. Consulte [FreeExtra](#freeextra) para obter um exemplo de como chamar essa função.

##  <a name="getat"></a>CSimpleStringT::GetAt

Retorna um caractere de um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
XCHAR GetAt(int iChar) const;
```

#### <a name="parameters"></a>Parâmetros

*iChar*<br/>
Índice de base zero do caractere no objeto `CSimpleStringT`. O parâmetro *iChar* deve ser maior ou igual a 0 e menor que o valor retornado por [GetLength](#getlength). Caso contrário, `GetAt` gerará uma exceção.

### <a name="return-value"></a>Valor retornado

Um `XCHAR` que contém o caractere na posição especificada na cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame esse método para retornar um caractere especificado por *iChar*. O operador de subscript sobrecarregado ( **[]** ) é um alias conveniente para `GetAt`. O terminador nulo é endereçável sem gerar uma exceção usando `GetAt`. No entanto, ele não é contado por `GetLength`, e o valor retornado é 0.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra como usar `CSimpleStringT::GetAt`.

```cpp
CSimpleString s(_T("abcdef"), pMgr);
ASSERT(s.GetAt(2) == _T('c'));
```

##  <a name="getbuffer"></a>CSimpleStringT::GetBuffer

Retorna um ponteiro para o buffer de caracteres interno do objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
PXSTR GetBuffer(int nMinBufferLength);
PXSTR GetBuffer();
```

#### <a name="parameters"></a>Parâmetros

*nMinBufferLength*<br/>
O número mínimo de caracteres que o buffer de caracteres pode conter. Esse valor não inclui espaço para um terminador nulo.

Se *nMinBufferLength* for maior que o comprimento do buffer atual, `GetBuffer` destruir o buffer atual, o substituirá por um buffer do tamanho solicitado e redefinirá a contagem de referência do objeto como zero. Se você já tiver chamado [LockBuffer](#lockbuffer) nesse buffer, perderá o bloqueio de buffer.

### <a name="return-value"></a>Valor retornado

Um ponteiro de `PXSTR` para o buffer de caracteres do objeto (terminada em nulo).

### <a name="remarks"></a>Comentários

Chame esse método para retornar o conteúdo do buffer do objeto de `CSimpleStringT`. O `PXSTR` retornado não é uma constante e, portanto, permite a modificação direta de conteúdo de `CSimpleStringT`.

Se você usar o ponteiro retornado por `GetBuffer` para alterar o conteúdo da cadeia de caracteres, deverá chamar [ReleaseBuffer](#releasebuffer) antes de usar qualquer outro método de membro `CSimpleStringT`.

O endereço retornado por `GetBuffer` pode não ser válido após a chamada para `ReleaseBuffer` porque as operações de `CSimpleStringT` adicionais podem fazer com que o buffer de `CSimpleStringT` seja realocado. O buffer não será realocado se você não alterar o comprimento do `CSimpleStringT`.

A memória de buffer é liberada automaticamente quando o objeto de `CSimpleStringT` é destruído.

Se você mesmo acompanhar o comprimento da cadeia de caracteres, não deverá acrescentar o caractere nulo de terminação. No entanto, você deve especificar o comprimento final da cadeia de caracteres ao liberar o buffer com `ReleaseBuffer`. Se você acrescentar um caractere nulo de terminação, deverá passar-1 (o padrão) para o comprimento. `ReleaseBuffer`, em seguida, determina o tamanho do buffer.

Se não houver memória suficiente para atender à solicitação de `GetBuffer`, esse método lançará um CMemoryException *.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
CSimpleString s(_T("abcd"), pMgr);
LPTSTR pBuffer = s.GetBuffer(10);
int sizeOfBuffer = s.GetAllocLength();

// Directly access CSimpleString buffer
_tcscpy_s(pBuffer, sizeOfBuffer, _T("Hello"));
ASSERT(_tcscmp(s, _T("Hello")) == 0);
s.ReleaseBuffer();
```

##  <a name="getbuffersetlength"></a>CSimpleStringT::GetBufferSetLength

Retorna um ponteiro para o buffer de caracteres interno para o objeto `CSimpleStringT`, truncando ou aumentando seu comprimento, se necessário, corresponder exatamente ao comprimento especificado em *nLength*.

### <a name="syntax"></a>Sintaxe

```
PXSTR GetBufferSetLength(int nLength);
```

#### <a name="parameters"></a>Parâmetros

*nLength*<br/>
O tamanho exato do buffer de caracteres de `CSimpleStringT` em caracteres.

### <a name="return-value"></a>Valor retornado

Um ponteiro de `PXSTR` para o buffer de caracteres do objeto (terminada em nulo).

### <a name="remarks"></a>Comentários

Chame esse método para recuperar um comprimento especificado do buffer interno do objeto `CSimpleStringT`. O ponteiro de `PXSTR` retornado não é **constante** e, portanto, permite a modificação direta de conteúdo de `CSimpleStringT`.

Se você usar o ponteiro retornado por [GetBufferSetLength](#getbuffersetlength) para alterar o conteúdo da cadeia de caracteres, chame `ReleaseBuffer` para atualizar o estado interno de `CsimpleStringT` antes de usar qualquer outro método de `CSimpleStringT`.

O endereço retornado por `GetBufferSetLength` pode não ser válido após a chamada para `ReleaseBuffer` porque as operações de `CSimpleStringT` adicionais podem fazer com que o buffer de `CSimpleStringT` seja realocado. O buffer não será reatribuído se você não alterar o comprimento do `CSimpleStringT`.

A memória de buffer é liberada automaticamente quando o objeto de `CSimpleStringT` é destruído.

Se você mesmo acompanhar o comprimento da cadeia de caracteres, não acrescente o caractere nulo de terminação. Você deve especificar o comprimento final da cadeia de caracteres ao liberar o buffer usando `ReleaseBuffer`. Se você acrescentar um caractere nulo de terminação ao chamar `ReleaseBuffer`, Pass-1 (o padrão) pelo comprimento para `ReleaseBuffer`e `ReleaseBuffer` executará uma `strlen` no buffer para determinar seu comprimento.

Para obter mais informações sobre a contagem de referência, consulte os seguintes artigos:

- [Gerenciamento de tempos de vida de objeto por meio de contagem de referência](/windows/win32/com/managing-object-lifetimes-through-reference-counting) no SDK do Windows.

- [Implementando a contagem de referência](/windows/win32/com/implementing-reference-counting) no SDK do Windows.

- [Regras para gerenciar contagens de referência](/windows/win32/com/rules-for-managing-reference-counts) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

##  <a name="getlength"></a>CSimpleStringT::GetLength

Retorna o número de caracteres no objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
int GetLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Uma contagem dos caracteres na cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame esse método para retornar o número de caracteres no objeto. A contagem não inclui um terminador nulo.

Para os conjuntos de caracteres multibyte (MBCS), `GetLength` conta cada caractere de 8 bits; ou seja, um byte de Lead e trilha em um caractere multibyte são contados como dois bytes. Consulte [FreeExtra](#freeextra) para obter um exemplo de como chamar essa função.

##  <a name="getmanager"></a>CSimpleStringT:: GetManager

Recupera o Gerenciador de memória do objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
IAtlStringMgr* GetManager() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o Gerenciador de memória para o objeto `CSimpleStringT`.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o Gerenciador de memória usado pelo objeto `CSimpleStringT`. Para obter mais informações sobre os gerenciadores de memória e objetos de cadeia de caracteres, consulte [Gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).

##  <a name="getstring"></a>CSimpleStringT:: GetString

Recupera a cadeia de caracteres.

### <a name="syntax"></a>Sintaxe

```
PCXSTR GetString() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma cadeia de caracteres de caractere terminada em nulo.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar a cadeia de caracteres associada ao objeto `CSimpleStringT`.

> [!NOTE]
>  O ponteiro de `PCXSTR` retornado é **const** e não permite a modificação direta de conteúdo de `CSimpleStringT`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::GetString`.

```cpp
CSimpleString str(pMgr);
str += _T("Cup soccer is best!");
_tprintf_s(_T("%s"), str.GetString());
```

##  <a name="isempty"></a>CSimpleStringT:: IsEmpty

Testa um objeto `CSimpleStringT` para a condição vazia.

### <a name="syntax"></a>Sintaxe

```
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o objeto `CSimpleStringT` tiver comprimento 0; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame esse método para determinar se o objeto contém uma cadeia de caracteres vazia.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::IsEmpty`.

```cpp
CSimpleString s(pMgr);
ASSERT(s.IsEmpty());
```

##  <a name="lockbuffer"></a>CSimpleStringT::LockBuffer

Desabilita a contagem de referência e protege a cadeia de caracteres no buffer.

### <a name="syntax"></a>Sintaxe

```
PXSTR LockBuffer();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CSimpleStringT` ou uma cadeia de caracteres terminada em nulo.

### <a name="remarks"></a>Comentários

Chame esse método para bloquear o buffer do objeto `CSimpleStringT`. Ao chamar `LockBuffer`, você cria uma cópia da cadeia de caracteres, com um-1 para a contagem de referência. Quando o valor da contagem de referência é-1, a cadeia de caracteres no buffer é considerada como em um estado "bloqueado". Enquanto estiver em um estado bloqueado, a cadeia de caracteres será protegida de duas maneiras:

- Nenhuma outra cadeia de caracteres pode obter uma referência aos dados na cadeia de caracteres bloqueada, mesmo se essa cadeia de caracteres for atribuída à cadeia de caracteres bloqueada.

- A cadeia de caracteres bloqueada nunca fará referência a outra cadeia de caracteres, mesmo se essa outra cadeia de caracteres for copiada na cadeia de caracteres bloqueada.

Ao bloquear a cadeia de caracteres no buffer, você garante que a espera exclusiva da cadeia de caracteres no buffer permanecerá intacta.

Depois de concluir a `LockBuffer`, chame [UnlockBuffer](#unlockbuffer) para redefinir a contagem de referência como 1.

> [!NOTE]
>  Se você chamar [GetBuffer](#getbuffer) em um buffer bloqueado e definir o parâmetro `GetBuffer` `nMinBufferLength` como maior que o comprimento do buffer atual, perderá o bloqueio de buffer. Tal chamada para `GetBuffer` destrói o buffer atual, substitui-o por um buffer do tamanho solicitado e redefine a contagem de referência como zero.

Para obter mais informações sobre a contagem de referência, consulte os seguintes artigos:

- [Gerenciando tempos de vida de objeto por meio de contagem de referência](/windows/win32/com/managing-object-lifetimes-through-reference-counting) no SDK do Windows

- [Implementando a contagem de referência](/windows/win32/com/implementing-reference-counting) no SDK do Windows

- [Regras para gerenciar contagens de referência](/windows/win32/com/rules-for-managing-reference-counts) no SDK do Windows

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::LockBuffer`.

```cpp
CSimpleString str(_T("Hello"), pMgr);
TCHAR ch;

str.LockBuffer();
ch = str.GetAt(2);
_tprintf_s(_T("%c"), ch);
str.UnlockBuffer();
```

##  <a name="operator_at"></a>CSimpleStringT:: Operator\[\]

Chame essa função para acessar um único caractere da matriz de caracteres.

### <a name="syntax"></a>Sintaxe

```
XCHAR operator[](int iChar) const;
```

#### <a name="parameters"></a>Parâmetros

*iChar*<br/>
Índice de base zero de um caractere na cadeia de caracteres.

### <a name="remarks"></a>Comentários

O operador de subscript sobrecarregado ( **[]** ) retorna um único caractere especificado pelo índice de base zero em *iChar*. Esse operador é um substituto conveniente para a função de membro [GetAt](#getat) .

> [!NOTE]
>  Você pode usar o operador de subscript ( **[]** ) para obter o valor de um caractere em uma `CSimpleStringT`, mas não pode usá-lo para alterar o valor de um caractere em uma `CSimpleStringT`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::operator []`.

```cpp
CSimpleString s(_T("abc"), pMgr);
ASSERT(s[1] == _T('b'));
```

## <a name="operator_at"></a>CSimpleStringT:: Operator \[\]

Chame essa função para acessar um único caractere da matriz de caracteres.

### <a name="syntax"></a>Sintaxe

```
XCHAR operator[](int iChar) const;
```

### <a name="parameters"></a>Parâmetros

*iChar*<br/>
Índice de base zero de um caractere na cadeia de caracteres.

### <a name="remarks"></a>Comentários

O operador de subscript sobrecarregado ( **[]** ) retorna um único caractere especificado pelo índice de base zero em *iChar*. Esse operador é um substituto conveniente para a função de membro [GetAt](#getat) .

> [!NOTE]
>  Você pode usar o operador de subscript ( **[]** ) para obter o valor de um caractere em uma `CSimpleStringT`, mas não pode usá-lo para alterar o valor de um caractere em uma `CSimpleStringT`.

##  <a name="operator_add_eq"></a>CSimpleStringT:: Operator + =

Une uma nova cadeia de caracteres ou caractere ao final de uma cadeia de caracteres existente.

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
Um ponteiro para uma cadeia de caracteres terminada em nulo.

*strSrc*<br/>
Um ponteiro para um objeto de `CSimpleStringT` existente.

*CH*<br/>
O caractere a ser acrescentado.

### <a name="remarks"></a>Comentários

O operador aceita outro objeto `CSimpleStringT` ou um caractere. Observe que as exceções de memória podem ocorrer sempre que você usar esse operador de concatenação porque um novo armazenamento pode ser alocado para caracteres adicionados a esse objeto de `CSimpleStringT`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::operator +=`.

```cpp
CSimpleString str(_T("abc"), pMgr);
ASSERT(_tcscmp((str += _T("def")), _T("abcdef")) == 0);
```

##  <a name="operator_eq"></a>CSimpleStringT:: Operator =

Atribui um novo valor a um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
CSimpleStringT& operator =(PCXSTR pszSrc);
CSimpleStringT& operator =(const CSimpleStringT& strSrc);
```

#### <a name="parameters"></a>Parâmetros

*pszSrc*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo.

*strSrc*<br/>
Um ponteiro para um objeto de `CSimpleStringT` existente.

### <a name="remarks"></a>Comentários

Se a cadeia de caracteres de destino (o lado esquerdo) já for grande o suficiente para armazenar os novos dados, nenhuma alocação de memória nova será executada. Observe que as exceções de memória podem ocorrer sempre que você usar o operador de atribuição porque um novo armazenamento geralmente é alocado para manter o objeto `CSimpleStringT` resultante.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

##  <a name="operator_pcxstr"></a>Operador CSimpleStringT:: Operator PCXSTR

Acessa diretamente os caracteres armazenados em um objeto `CSimpleStringT` como uma cadeia de estilo C.

### <a name="syntax"></a>Sintaxe

```
operator PCXSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro de caractere para os dados da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Nenhum caractere copiado; apenas um ponteiro é retornado. Tenha cuidado com esse operador. Se você alterar um objeto `CString` depois de obter o ponteiro de caractere, poderá causar uma realocação de memória que invalida o ponteiro.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

##  <a name="pcxstr"></a>CSimpleStringT::P CXSTR

Um ponteiro para uma cadeia de caracteres constante.

### <a name="syntax"></a>Sintaxe

```
typedef ChTraitsBase< BaseType >::PCXSTR PCXSTR;
```

##  <a name="preallocate"></a>CSimpleStringT::P realocar

Aloca uma quantidade específica de bytes para o objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
void Preallocate( int nLength);
```

#### <a name="parameters"></a>Parâmetros

*nLength*<br/>
O tamanho exato do buffer de caracteres de `CSimpleStringT` em caracteres.

### <a name="remarks"></a>Comentários

Chame esse método para alocar um tamanho de buffer específico para o objeto `CSimpleStringT`.

`CSimpleStringT` gerará uma exceção de STATUS_NO_MEMORY se não for possível alocar espaço para o buffer de caracteres. Por padrão, a alocação de memória é executada pelas funções de API do WIN32 `HeapAlloc` ou `HeapReAlloc`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::Preallocate`.

```cpp
CSimpleString str(pMgr);
_tprintf_s(_T("Allocated length: %d\n"), str.GetAllocLength());
str.Preallocate(100);
_tprintf_s(_T("Allocated length: %d\n"), str.GetAllocLength());
```

##  <a name="pxstr"></a>CSimpleStringT::P XSTR

Um ponteiro para uma cadeia de caracteres.

### <a name="syntax"></a>Sintaxe

```
typedef ChTraitsBase< BaseType >::PXSTR PXSTR;
```

##  <a name="releasebuffer"></a>CSimpleStringT::ReleaseBuffer

Libera o controle do buffer alocado por [GetBuffer](#getbuffer).

### <a name="syntax"></a>Sintaxe

```
void ReleaseBuffer(int nNewLength = -1);
```

#### <a name="parameters"></a>Parâmetros

*nNewLength*<br/>
O novo comprimento da cadeia em caracteres, não contando um terminador nulo. Se a cadeia de caracteres for terminada em nulo, o valor padrão-1 definirá o tamanho de `CSimpleStringT` como o comprimento atual da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame esse método para realocar ou liberar o buffer do objeto de cadeia de caracteres. Se você souber que a cadeia de caracteres no buffer é terminada em nulo, você pode omitir o argumento *nNewLength* . Se a cadeia de caracteres não for terminada em nulo, use *nNewLength* para especificar seu comprimento. O endereço retornado por [GetBuffer](#getbuffer) é inválido após a chamada para `ReleaseBuffer` ou qualquer outra operação de `CSimpleStringT`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

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

##  <a name="releasebuffersetlength"></a>CSimpleStringT::ReleaseBufferSetLength

Libera o controle do buffer alocado por [GetBuffer](#getbuffer).

### <a name="syntax"></a>Sintaxe

```
void ReleaseBufferSetLength(int nNewLength);
```

#### <a name="parameters"></a>Parâmetros

*nNewLength*<br/>
O comprimento da cadeia de caracteres que está sendo liberada

### <a name="remarks"></a>Comentários

Essa função é funcionalmente semelhante a [ReleaseBuffer](#releasebuffer) , exceto que um comprimento válido para o objeto de cadeia de caracteres deve ser passado.

##  <a name="setat"></a>CSimpleStringT::SetAt

Define um único caractere de um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
void SetAt(int iChar, XCHAR ch);
```

#### <a name="parameters"></a>Parâmetros

*iChar*<br/>
Índice de base zero do caractere no objeto `CSimpleStringT`. O parâmetro *iChar* deve ser maior ou igual a 0 e menor que o valor retornado por [GetLength](#getlength).

*CH*<br/>
O novo caractere.

### <a name="remarks"></a>Comentários

Chame esse método para substituir o caractere localizado em *iChar*. Esse método não ampliará a cadeia de caracteres se *iChar* exceder os limites da cadeia de caracteres existente.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::SetAt`.

```cpp
CSimpleString s(_T("abcdef"), pMgr);
s.SetAt(1, _T('a'));
ASSERT(_tcscmp(s, _T("aacdef")) == 0);
```

##  <a name="setmanager"></a>CSimpleStringT:: SetManager

Especifica o Gerenciador de memória do objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
void SetManager(IAtlStringMgr* pStringMgr);
```

#### <a name="parameters"></a>Parâmetros

*pStringMgr*<br/>
Um ponteiro para o novo Gerenciador de memória.

### <a name="remarks"></a>Comentários

Chame esse método para especificar um novo Gerenciador de memória usado pelo objeto `CSimpleStringT`. Para obter mais informações sobre os gerenciadores de memória e objetos de cadeia de caracteres, consulte [Gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::SetManager`.

```cpp
CSimpleString s(pMgr);
s.SetManager(pCustomMgr);
```

##  <a name="setstring"></a>CSimpleStringT:: SetString

Define a cadeia de caracteres de um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
void SetString(PCXSTR pszSrc, int nLength);
void SetString(PCXSTR pszSrc);
```

#### <a name="parameters"></a>Parâmetros

*pszSrc*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo.

*nLength*<br/>
Uma contagem do número de caracteres em *pszSrc*.

### <a name="remarks"></a>Comentários

Copie uma cadeia de caracteres no objeto `CSimpleStringT`. `SetString` substitui os dados de cadeia de caracteres mais antigos no buffer.

Ambas as versões do `SetString` verificar se *pszSrc* é um ponteiro nulo e, se for, lançar um erro de E_INVALIDARG.

A versão de um parâmetro do `SetString` espera que *pszSrc* aponte para uma cadeia de caracteres terminada em nulo.

A versão de dois parâmetros do `SetString` também espera que *pszSrc* seja uma cadeia de caracteres terminada em nulo. Ele usa *nLength* como o comprimento da cadeia de caracteres, a menos que ele encontre um terminador nulo primeiro.

A versão de dois parâmetros do `SetString` também verifica se *pszSrc* aponta para um local no buffer atual em `CSimpleStringT`. Nesse caso especial, `SetString` usa uma função de cópia de memória que não substitui os dados de cadeia de caracteres à medida que copia os dados de cadeia de caracteres de volta para seu buffer.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::SetString`.

```cpp
CSimpleString s(_T("abcdef"), pMgr);
ASSERT(_tcscmp(s, _T("abcdef")) == 0);
s.SetString(_T("Soccer"), 6);
ASSERT(_tcscmp(s, _T("Soccer")) == 0);
```

##  <a name="stringlength"></a>CSimpleStringT::StringLength

Retorna o número de caracteres na cadeia de caracteres especificada.

### <a name="syntax"></a>Sintaxe

```
ATL_NOINLINE static int StringLength(PCXSTR psz) throw();
```

#### <a name="parameters"></a>Parâmetros

*psz*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo.

### <a name="return-value"></a>Valor retornado

O número de caracteres em *psz*; Não contando um terminador nulo.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de caracteres na cadeia de caracteres apontada por *psz*.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::StringLength`.

```cpp
ASSERT(CSimpleString::StringLength(_T("soccer")) == 6);
```

##  <a name="truncate"></a>CSimpleStringT:: TRUNCATE

Trunca a cadeia de caracteres para o novo comprimento.

### <a name="syntax"></a>Sintaxe

```
void Truncate(int nNewLength);
```

#### <a name="parameters"></a>Parâmetros

*nNewLength*<br/>
O novo comprimento da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame esse método para truncar o conteúdo da cadeia de caracteres para o novo comprimento.

> [!NOTE]
>  Isso não afeta o comprimento alocado do buffer. Para diminuir ou aumentar o buffer atual, consulte [FreeExtra](#freeextra) e [preallocate](#preallocate).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra o uso de `CSimpleStringT::Truncate`.

```cpp
CSimpleString str(_T("abcdefghi"), pMgr);
_tprintf_s(_T("Allocated length: %d\n"), str.GetLength());
_tprintf_s(_T("Contents: %s\n"), str);
str.Truncate(4);
_tprintf_s(_T("Allocated length: %d\n"), str.GetLength());
_tprintf_s(_T("Contents: %s\n"), str);
```

##  <a name="unlockbuffer"></a>CSimpleStringT::UnlockBuffer

Desbloqueia o buffer do objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
void UnlockBuffer() throw();
```

### <a name="remarks"></a>Comentários

Chame esse método para redefinir a contagem de referência da cadeia de caracteres para 1.

O destruidor `CSimpleStringT` chama automaticamente `UnlockBuffer` para garantir que o buffer não seja bloqueado quando o destruidor é chamado. Para obter um exemplo desse método, consulte [LockBuffer](#lockbuffer).

##  <a name="dtor"></a>CSimpleStringT:: ~ CSimpleStringT

Destrói um objeto `CSimpleStringT`.

### <a name="syntax"></a>Sintaxe

```
~CSimpleStringT() throw();
```

### <a name="remarks"></a>Comentários

Chame esse método para destruir o objeto `CSimpleStringT`.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
