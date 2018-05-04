---
title: Classe CSimpleStringT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- shared classes, CSimpleStringT
- strings [C++], ATL class
- CSimpleStringT class
ms.assetid: 15814fcb-5b8f-4425-a97e-3b61fc9b48d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a7dc68cd1d91cb7b651dbeb68422f6a89fb9f2f8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="csimplestringt-class"></a>Classe CSimpleStringT
Essa classe representa um `CSimpleStringT` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename BaseType>
class CSimpleStringT
```  
  
### <a name="parameters"></a>Parâmetros  
 `BaseType`  
 O tipo de caractere da classe string. Pode ser um dos seguintes:  
  
- `char` (para cadeias de caracteres ANSI).  
  
- `wchar_t` (para cadeias de caracteres Unicode).  
  
- **TCHAR** (para cadeias de caracteres ANSI e Unicode).  

## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleStringT::PCXSTR](#pcxstr)|Um ponteiro para uma cadeia de caracteres constante.|  
|[CSimpleStringT::PXSTR](#pxstr)|Um ponteiro para uma cadeia de caracteres.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleStringT::CSimpleStringT](#ctor)|Constrói `CSimpleStringT` objetos de várias maneiras.|  
|[CSimpleStringT:: ~ CSimpleStringT](#dtor)|Destruidor.|  

  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleStringT::Append](#append)|Acrescenta um `CSimpleStringT` objeto um existente `CSimpleStringT` objeto.|  
|[CSimpleStringT::AppendChar](#appendchar)|Acrescenta um caractere de um existente `CSimpleStringT` objeto.|  
|[CSimpleStringT::CopyChars](#copychars)|Copia um ou mais caracteres em outra cadeia de caracteres.|  
|[CSimpleStringT::CopyCharsOverlapped](#copycharsoverlapped)|Copia um ou mais caracteres em outra cadeia de caracteres na qual os buffers se sobrepõem.|  
|[CSimpleStringT::Empty](#empty)|Força uma cadeia de caracteres com comprimento zero.|  
|[CSimpleStringT::FreeExtra](#freeextra)|Libera qualquer memória extra anteriormente alocada pelo objeto de cadeia de caracteres.|  
|[CSimpleStringT::GetAllocLength](#getalloclength)|Recupera o tamanho alocado de um `CSimpleStringT` objeto.|  
|[CSimpleStringT::GetAt](#getat)|Retorna o caractere na posição especificada.|  
|[CSimpleStringT::GetBuffer](#getbuffer)|Retorna um ponteiro para os caracteres em um `CSimpleStringT`.|  
|[CSimpleStringT::GetBufferSetLength](#getbuffersetlength)|Retorna um ponteiro para os caracteres em um `CSimpleStringT`, truncando para o comprimento especificado.|  
|[CSimpleStringT::GetLength](#getlength)|Retorna o número de caracteres em um `CSimpleStringT` objeto.|  
|[CSimpleStringT::GetManager](#getmanager)|Recupera o Gerenciador de memória do `CSimpleStringT` objeto.|  
|[CSimpleStringT::GetString](#getstring)|Recupera a cadeia de caracteres|  
|[CSimpleStringT::IsEmpty](#isempty)|Testes se um `CSimpleStringT` objeto não contém nenhum caractere.|  
|[CSimpleStringT::LockBuffer](#lockbuffer)|Desabilita a contagem de referência e protege a cadeia de caracteres no buffer.|  
|[CSimpleStringT::Preallocate](#preallocate)|Aloca uma quantidade específica de memória para o buffer de caractere.|  
|[CSimpleStringT::ReleaseBuffer](#releasebuffer)|Libera o controle do buffer retornado por `GetBuffer`.|  
|[CSimpleStringT::ReleaseBufferSetLength](#releasebuffersetlength)|Libera o controle do buffer retornado por `GetBuffer`.|  
|[CSimpleStringT::SetAt](#setat)|Define um caractere na posição especificada.|  
|[CSimpleStringT::SetManager](#setmanager)|Define o Gerenciador de memória de um `CSimpleStringT` objeto.|  
|[CSimpleStringT::SetString](#setstring)|Define a cadeia de caracteres de um `CSimpleStringT` objeto.|  
|[CSimpleStringT::StringLength](#stringlength)|Retorna o número de caracteres na cadeia de caracteres especificada.|  
|[CSimpleStringT::Truncate](#truncate)|Trunca a cadeia de caracteres para um comprimento especificado.|  
|[CSimpleStringT::UnlockBuffer](#unlockbuffer)|Habilita a contagem de referência e libera a cadeia de caracteres no buffer.|  

### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSimpleStringT::operator PCXSTR](#operator_pcxstr)|Acessa diretamente caracteres armazenados em uma `CSimpleStringT` objeto como uma cadeia de caracteres de estilo C.|  
|[CSimpleStringT::operator\[\]](#operator_at)|Retorna o caractere na posição especificada, a substituição de operador para `GetAt`.|  
|[+ CSimpleStringT::operator =](#operator_add_eq)|Concatena uma nova cadeia de caracteres ao final de uma cadeia de caracteres existente.|  
|[CSimpleStringT::operator =](#operator_eq)|Atribui um novo valor para uma `CSimpleStringT` objeto.|  
  
### <a name="remarks"></a>Comentários  
 `CSimpleStringT` é a classe base para as várias classes de cadeia de caracteres com suporte do Visual C++. Ele fornece suporte mínimo para o gerenciamento de memória do objeto de cadeia de caracteres e manipulação de buffer básico. Para objetos de cadeia de caracteres mais avançados, consulte [CStringT classe](../../atl-mfc-shared/reference/cstringt-class.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlsimpstr.h  


## <a name="append"></a> CSimpleStringT::Append
Acrescenta um `CSimpleStringT` objeto um existente `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void Append(const CSimpleStringT& strSrc); 
void Append(PCXSTR pszSrc, int nLength); 
void Append(PCXSTR pszSrc);
```  
#### <a name="parameters"></a>Parâmetros  
 `strSrc`  
 O `CSimpleStringT` objeto a ser anexado.  
  
 `pszSrc`  
 Um ponteiro para uma cadeia de caracteres que contém os caracteres a serem acrescentados.  
  
 `nLength`  
 O número de caracteres a serem acrescentados.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para acrescentar um existente `CSimpleStringT` objeto para outro `CSimpleStringT` objeto.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::Append`.  
  
```cpp  
CSimpleString str1(pMgr), str2(pMgr);
str1.SetString(_T("Soccer is"));
str2.SetString(_T(" an elegant game"));
str1.Append(str2);
ASSERT(_tcscmp(str1, _T("Soccer is an elegant game")) == 0);
```
  
##  <a name="appendchar"></a> CSimpleStringT::AppendChar
Acrescenta um caractere de um existente `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void AppendChar(XCHAR ch);
```  
#### <a name="parameters"></a>Parâmetros  
 *ch*  
 O caractere a ser anexado  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função para acrescentar o caractere especificado ao final de um objeto existente `CSimpleStringT` objeto.  
  
##  <a name="copychars"></a> CSimpleStringT::CopyChars  
 Copia um ou mais caracteres para um `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static void CopyChars(
  XCHAR* pchDest,
  const XCHAR* pchSrc, 
  int nChars) throw();
```  
#### <a name="parameters"></a>Parâmetros  
 `pchDest`  
 Um ponteiro para uma cadeia de caracteres.  
  
 `pchSrc`  
 Um ponteiro para uma cadeia de caracteres que contém os caracteres a serem copiados.  
  
 `nChars`  
 O número de `pchSrc` caracteres a serem copiados.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para copiar os caracteres de `pchSrc` para o `pchDest` cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::CopyChars`.  
  
```cpp  
CSimpleString str(_T("xxxxxxxxxxxxxxxxxxx"), 20, pMgr);
TCHAR* pszSrc = _T("Hello world!");
_tprintf_s(_T("%s\n"), str);
str.CopyChars(str.GetBuffer(), pszSrc, 12);
_tprintf_s(_T("%s\n"), str);
```
  
##  <a name="copycharsoverlapped"></a>  CSimpleStringT::CopyCharsOverlapped
Copia um ou mais caracteres para um `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
static void CopyCharsOverlapped(
  XCHAR* pchDest,
  const XCHAR* pchSrc,
  int nChars) throw(); 
```  
#### <a name="parameters"></a>Parâmetros  
 `pchDest`  
 Um ponteiro para uma cadeia de caracteres.  
  
 `pchSrc`  
 Um ponteiro para uma cadeia de caracteres que contém os caracteres a serem copiados.  
  
 `nChars`  
 O número de `pchSrc` caracteres a serem copiados.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para copiar os caracteres de `pchSrc` para o `pchDest` cadeia de caracteres. Ao contrário de `CopyChars`, `CopyCharsOverlapped` fornece um método de seguro para a cópia dos buffers de caracteres que podem ser sobrepostos.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [CSimpleStringT::CopyChars](#copychars), ou o código-fonte para `CSimpleStringT::SetString` (localizado em atlsimpstr.h).  
  
##  <a name="ctor"></a>  CSimpleStringT::CSimpleStringT  
 Constrói um objeto `CSimpleStringT`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
CSimpleStringT(const XCHAR* pchSrc, int nLength, IAtlStringMgr* pStringMgr); 
CSimpleStringT(PCXSTR pszSrc, IAtlStringMgr* pStringMgr); 
CSimpleStringT(const CSimpleStringT& strSrc); 
explicit CSimpleStringT(IAtlStringMgr* pStringMgr) throw(); 
```  
#### <a name="parameters"></a>Parâmetros  
 `strSrc`  
 Um existente `CSimpleStringT` objeto sejam copiados para este `CSimpleStringT` objeto.  
  
 `pchSrc`  
 Um ponteiro para uma matriz de caracteres de comprimento `nLength`, não terminada nula.  
  
 `pszSrc`  
 Uma cadeia de caracteres terminada em nulo a serem copiados nisso `CSimpleStringT` objeto.  
  
 `nLength`  
 Uma contagem do número de caracteres em `pch`.  
  
 `pStringMgr`  
 Um ponteiro para o Gerenciador de memória do `CSimpleStringT` objeto. Para obter mais informações sobre `IAtlStringMgr` e gerenciamento de memória para `CSimpleStringT`, consulte [gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).  
  
### <a name="remarks"></a>Comentários  
 Criar um novo `CSimpleStringT` objeto. Como os construtores copiar os dados de entrada para o novo armazenamento alocado, exceções de memória podem acontecer.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::CSimpleStringT` usando a ATL `typedef` `CSimpleString`. `CSimpleString` é uma especialização de usada geral do modelo de classe `CSimpleStringT`.  
  
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

  
##  <a name="empty"></a>  CSimpleStringT::Empty
Torna isso `CSimpleStringT` uma cadeia de caracteres vazia do objeto e libera memória conforme apropriado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void Empty() throw();  
```  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [cadeias de caracteres: limpeza de exceção de CString](../cstring-exception-cleanup.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::Empty`.  
  
```cpp  
CSimpleString s(pMgr);
ASSERT(s.IsEmpty());  
```  
  
##  <a name="freeextra"></a>  CSimpleStringT::FreeExtra
Libera qualquer memória extra distribuído anteriormente pela cadeia de caracteres, mas são mais necessários.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void FreeExtra(); 
```  
### <a name="remarks"></a>Comentários  
 Isso deve reduzir a sobrecarga de memória consumida pelo objeto de cadeia de caracteres. O método realoca o buffer para o comprimento exato retornado por [GetLength](#getlength).  
  
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
 A saída deste exemplo é o seguinte:  
  
 `Alloc length is 1031, String length is 1024`  
  
 `Alloc length is 1031, String length is 15`  
  
 `Alloc length is 15, String length is 15`  
  
##  <a name="getalloclength"></a>  CSimpleStringT::GetAllocLength  
Recupera o tamanho alocado de um `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
int GetAllocLength() const throw();  
```  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres alocado para este objeto.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para determinar o número de caracteres alocado para essa `CSimpleStringT` objeto. Consulte [FreeExtra](#freeextra) para obter um exemplo de chamar essa função.  
  
##  <a name="getat"></a>  CSimpleStringT::GetAt  
Retorna um caractere de um `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
XCHAR GetAt(int iChar) const;
```  
#### <a name="parameters"></a>Parâmetros  
 `iChar`  
 Índice de base zero do caractere de `CSimpleStringT` objeto. O `iChar` parâmetro deve ser maior que ou igual a 0 e menor que o valor retornado por [GetLength](#getlength). Caso contrário, `GetAt` gerará uma exceção.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `XCHAR` que contém o caractere na posição especificada na cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para retornar a um caractere especificado por `iChar`. A subscrição sobrecarregada (`[]`) operador é um alias conveniente para `GetAt`. O terminador nulo é endereçável sem gerar uma exceção usando `GetAt`. No entanto, não é contado por `GetLength`, e o valor retornado será 0.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar `CSimpleStringT::GetAt`.  
  
```cpp  
CSimpleString s(_T("abcdef"), pMgr);
ASSERT(s.GetAt(2) == _T('c'));
```
  
##  <a name="getbuffer"></a>  CSimpleStringT::GetBuffer  
Retorna um ponteiro para o buffer interno de caractere para o `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
PXSTR GetBuffer(int nMinBufferLength); 
PXSTR GetBuffer();
```  
#### <a name="parameters"></a>Parâmetros  
 `nMinBufferLength`  
 O número mínimo de caracteres que o buffer de caracteres pode conter. Esse valor não inclui o espaço para um terminador nulo.  
  
 Se `nMinBufferLength` é maior do que o comprimento do buffer atual, `GetBuffer` destrói o buffer atual, o substitui por um buffer do tamanho solicitado e redefine a contagem de referência de objeto para zero. Se você tiver chamado anteriormente [LockBuffer](#lockbuffer) esse buffer, você perderá o bloqueio de buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `PXSTR` ponteiro ao buffer de caractere (terminação nula) do objeto.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para retornar o conteúdo do buffer do `CSimpleStringT` objeto. Retornado `PXSTR` não é uma constante e, portanto, permite a modificação direta de `CSimpleStringT` conteúdo.  
  
 Se você usar o ponteiro retornado por `GetBuffer` para alterar o conteúdo de cadeia de caracteres, você deve chamar [ReleaseBuffer](#releasebuffer) antes de usar qualquer outra `CSimpleStringT` métodos de membro.  
  
 O endereço retornado por `GetBuffer` podem não ser válidas após a chamada a `ReleaseBuffer` porque adicionais `CSimpleStringT` operações podem fazer com que o `CSimpleStringT` buffer a ser realocados. O buffer não é realocado se você não alterar o comprimento do `CSimpleStringT`.  
  
 A memória de buffer automaticamente é liberado quando o `CSimpleStringT` objeto é destruído.  
  
 Se você controla o comprimento da cadeia de caracteres por conta própria, você não deve acrescentar o caractere null de terminação. No entanto, você deve especificar o comprimento da cadeia de caracteres final quando você liberar o buffer com `ReleaseBuffer`. Se você acrescentar um caractere null de terminação, você deve passar -1 (o padrão) para o comprimento. `ReleaseBuffer` em seguida, determina o comprimento do buffer.  
  
 Se não houver memória suficiente para atender a `GetBuffer` solicitar, este método lança um CMemoryException *.  
  
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
  
##  <a name="getbuffersetlength"></a>  CSimpleStringT::GetBufferSetLength  
Retorna um ponteiro para o buffer interno de caractere para a `CSimpleStringT` objeto, truncados ou aumentando seu comprimento, se necessário, para corresponder exatamente o comprimento especificado em `nLength`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
PXSTR GetBufferSetLength(int nLength);
```  
#### <a name="parameters"></a>Parâmetros  
 `nLength`  
 O tamanho exato do `CSimpleStringT` buffer de caracteres em caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `PXSTR` ponteiro ao buffer de caractere (terminação nula) do objeto.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o buffer interno de um período especificado de `CSimpleStringT` objeto. Retornado `PXSTR` ponteiro não é `const` , permitindo que a modificação direta de `CSimpleStringT` conteúdo.  
  
 Se você usar o ponteiro retornado por [GetBufferSetLength](#getbuffersetlength) para alterar o conteúdo de cadeia de caracteres, chame `ReleaseBuffer` para atualizar o estado interno de `CsimpleStringT` antes de usar qualquer outra `CSimpleStringT` métodos.  
  
 O endereço retornado por `GetBufferSetLength` podem não ser válidas após a chamada a `ReleaseBuffer` porque adicionais `CSimpleStringT` operações podem fazer com que o `CSimpleStringT` buffer a ser realocados. O buffer não é reatribuído se você não alterar o comprimento do `CSimpleStringT`.  
  
 A memória de buffer automaticamente é liberado quando o `CSimpleStringT` objeto é destruído.  
  
 Se você controla o comprimento da cadeia de caracteres por conta própria, não anexa o caractere null de terminação. Você deve especificar o comprimento da cadeia de caracteres final quando você liberar o buffer usando `ReleaseBuffer`. Se você acrescentar um caractere null de terminação quando você chamar `ReleaseBuffer`, passe -1 (o padrão) para o comprimento para `ReleaseBuffer`, e `ReleaseBuffer` executará um `strlen` em buffer para determinar seu tamanho.  
  
 Para obter mais informações sobre a contagem de referência, consulte os seguintes artigos:  
  
- [Gerenciamento de vida útil do objeto por meio de contagem de referência](http://msdn.microsoft.com/library/windows/desktop/ms687260) no SDK do Windows. 
  
- [Implementando a contagem de referência](http://msdn.microsoft.com/library/windows/desktop/ms693431) no SDK do Windows.
  
- [Regras de gerenciamento de contagens de referência](http://msdn.microsoft.com/library/windows/desktop/ms692481) no SDK do Windows.  
  
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
  
##  <a name="getlength"></a>  CSimpleStringT::GetLength  
Retorna o número de caracteres a `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
int GetLength() const throw();  
```  
### <a name="return-value"></a>Valor de retorno  
 Uma contagem de caracteres na cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para retornar o número de caracteres no objeto. A contagem não inclui um terminador nulo.  
  
 Para conjuntos de caracteres multibyte (MBCS) `GetLength` contagens de cada byte de caractere; ou seja, um cliente potencial e trilha de 8 bits em caracteres multibyte um são contados como dois bytes. Consulte [FreeExtra](#freeextra) para obter um exemplo de chamar essa função.  
  
##  <a name="getmanager"></a>  CSimpleStringT::GetManager  
Recupera o Gerenciador de memória do `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
IAtlStringMgr* GetManager() const throw();  
```  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o Gerenciador de memória para o `CSimpleStringT` objeto.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar a memória usado pelo Gerenciador do `CSimpleStringT` objeto. Para obter mais informações sobre gerenciadores de memória e objetos de cadeia de caracteres, consulte [gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).  
  
##  <a name="getstring"></a>  CSimpleStringT::GetString
Recupera a cadeia de caracteres.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
PCXSTR GetString() const throw();
```  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma cadeia de caracteres terminada em nulo.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar a cadeia de caracteres associada a `CSimpleStringT` objeto.  
  
> [!NOTE]
>  Retornado `PCXSTR` ponteiro é `const` e não permite a modificação direta de `CSimpleStringT` conteúdo.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::GetString`.  
  
```cpp  
CSimpleString str(pMgr);
str += _T("Cup soccer is best!");
_tprintf_s(_T("%s"), str.GetString());
```
  
##  <a name="isempty"></a>  CSimpleStringT::IsEmpty  
Testes de um `CSimpleStringT` objeto para a condição vazia.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool IsEmpty() const throw();  
```  
### <a name="return-value"></a>Valor de retorno  
 Retorna **true** se o `CSimpleStringT` objeto tem comprimento 0; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para determinar se o objeto contém uma cadeia de caracteres vazia.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::IsEmpty`.  
  
```cpp  
CSimpleString s(pMgr);
ASSERT(s.IsEmpty());
```
  
##  <a name="lockbuffer"></a>  CSimpleStringT::LockBuffer  
Desabilita a contagem de referência e protege a cadeia de caracteres no buffer.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
PXSTR LockBuffer();
```  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CSimpleStringT` objeto ou uma cadeia de caracteres terminada em nulo.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para bloquear o buffer do `CSimpleStringT` objeto. Chamando `LockBuffer`, você cria uma cópia da cadeia de caracteres, com um -1 para a contagem de referência. Quando o valor de contagem de referência é -1, a cadeia de caracteres no buffer é considerada para estar em um estado "bloqueado". Enquanto estiver em um estado bloqueado, a cadeia de caracteres é protegida de duas maneiras:  
  
-   Nenhuma outra cadeia de caracteres pode obter uma referência para os dados na cadeia de caracteres bloqueada, mesmo se essa cadeia de caracteres é atribuída à cadeia de caracteres bloqueada.  
  
-   A cadeia de caracteres bloqueada nunca fará referência a outra cadeia de caracteres, mesmo se outra cadeia de caracteres que é copiada para a cadeia de caracteres bloqueada.  
  
 Bloqueio a cadeia de caracteres no buffer, você garante que a espera exclusivo da cadeia de caracteres no buffer permanecerão intacta.  
  
 Depois de concluir a `LockBuffer`, chame [UnlockBuffer](#unlockbuffer) para redefinir a contagem de referência para 1.  
  
> [!NOTE]
>  Se você chamar [GetBuffer](#getbuffer) em um buffer bloqueado e defina o `GetBuffer` parâmetro `nMinBufferLength` maior que o comprimento do buffer atual, você perderá o bloqueio de buffer. Essa chamada para `GetBuffer` destrói o buffer atual, o substitui por um buffer do tamanho solicitado e redefine a contagem de referência como zero.  
  
 Para obter mais informações sobre a contagem de referência, consulte os seguintes artigos:  
  
- [Gerenciamento de vida útil do objeto por meio de contagem de referência](http://msdn.microsoft.com/library/windows/desktop/ms687260) no SDK do Windows  
  
- [Implementando a contagem de referência](http://msdn.microsoft.com/library/windows/desktop/ms693431) no SDK do Windows  
  
- [Regras de gerenciamento de contagens de referência](http://msdn.microsoft.com/library/windows/desktop/ms692481) no SDK do Windows  
  
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
  
##  <a name="operator_at"></a>  CSimpleStringT::operator\[\]  
Chame essa função para acessar um único caractere da matriz de caracteres.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
XCHAR operator[](int iChar) const;
```  
#### <a name="parameters"></a>Parâmetros  
 `iChar`  
 Índice de base zero de um caractere na cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 A subscrição sobrecarregada (`[]`) operador retorna um único caractere especificado pelo índice de base zero em `iChar`. Esse operador é um substituto conveniente para o [GetAt](#getat) função de membro.  
  
> [!NOTE]
>  Você pode usar o subscrito (`[]`) operador para obter o valor de um caractere em uma `CSimpleStringT`, mas você não pode usá-lo para alterar o valor de um caractere em um `CSimpleStringT`.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de **[CSimpleStringT::operator]**.  
  
```cpp  
CSimpleString s(_T("abc"), pMgr);
ASSERT(s[1] == _T('b'));
```
  
## <a name="operator_at"></a>  CSimpleStringT::operator \[\]
Chame essa função para acessar um único caractere da matriz de caracteres.  
  
### <a name="syntax"></a>Sintaxe  
  
```   
XCHAR operator[](int iChar) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `iChar`  
 Índice de base zero de um caractere na cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 A subscrição sobrecarregada (`[]`) operador retorna um único caractere especificado pelo índice de base zero em `iChar`. Esse operador é um substituto conveniente para o [GetAt](#getat) função de membro.  
  
> [!NOTE]
>  Você pode usar o subscrito (`[]`) operador para obter o valor de um caractere em uma `CSimpleStringT`, mas você não pode usá-lo para alterar o valor de um caractere em um `CSimpleStringT`.  
  
  
##  <a name="operator_add_eq"></a>  + CSimpleStringT::operator =  
Une uma nova cadeia de caracteres ou um caractere de final de uma cadeia de caracteres existente.  
  
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
 `pszSrc`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo.  
  
 `strSrc`  
 Um ponteiro para um existente `CSimpleStringT` objeto.  
  
 *ch*  
 O caractere a ser acrescentado.  
  
### <a name="remarks"></a>Comentários  
 O operador aceita outro `CSimpleStringT` objeto ou um caractere. Observe que a memória exceções podem ocorrer sempre que você usa este operador de concatenação, porque o novo armazenamento pode ser alocado para caracteres adicionados a este `CSimpleStringT` objeto.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de **+ CSimpleStringT::operator =**.  
  
```cpp  
CSimpleString str(_T("abc"), pMgr);
ASSERT(_tcscmp((str += _T("def")), _T("abcdef")) == 0);
```
  
##  <a name="operator_eq"></a>  CSimpleStringT::operator =  
Atribui um novo valor para uma `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
CSimpleStringT& operator =(PCXSTR pszSrc); 
CSimpleStringT& operator =(const CSimpleStringT& strSrc);
```  
#### <a name="parameters"></a>Parâmetros  
 `pszSrc`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo.  
  
 `strSrc`  
 Um ponteiro para um existente `CSimpleStringT` objeto.  
  
### <a name="remarks"></a>Comentários  
 Se a cadeia de caracteres de destino (o lado esquerdo) já for grande o suficiente para armazenar novos dados, nenhuma nova alocação de memória será executada. Observe que a memória exceções podem ocorrer sempre que você usar o operador de atribuição, porque o novo armazenamento geralmente é alocado para armazenar resultante `CSimpleStringT` objeto.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de **CSimpleStringT::operator =**.  
  
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
  
##  <a name="operator_pcxstr"></a>  CSimpleStringT::operator PCXSTR  

 Acessa diretamente caracteres armazenados em uma `CSimpleStringT` objeto como uma cadeia de caracteres de estilo C.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
operator PCXSTR() const throw();
```  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro de caractere para dados da cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Caracteres não é copiado; somente um ponteiro será retornado. Tenha cuidado com esse operador. Se você alterar uma `CString` objeto depois de obter o ponteiro de caractere, você pode causar uma realocação de memória que invalida o ponteiro.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de **CSimpleStringT::operator PCXSTR**.  
  
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
  
##  <a name="pcxstr"></a>  CSimpleStringT::PCXSTR
Um ponteiro para uma cadeia de caracteres constante.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef ChTraitsBase< BaseType >::PCXSTR PCXSTR;    
```  
##  <a name="preallocate"></a>  CSimpleStringT::Preallocate  
Aloca uma quantidade específica de bytes para o `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void Preallocate( int nLength);
```  
#### <a name="parameters"></a>Parâmetros  
 `nLength`  
 O tamanho exato do `CSimpleStringT` buffer de caracteres em caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para alocar um tamanho de buffer específico para o `CSimpleStringT` objeto.  
  
 `CSimpleStringT` gera um `STATUS_NO_MEMORY` exceção se não é possível alocar espaço para o buffer de caractere. Por padrão, a alocação de memória é executada pelas funções de API do WIN32 `HeapAlloc` ou `HeapReAlloc`.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::Preallocate`.  
  
```cpp  
CSimpleString str(pMgr);
_tprintf_s(_T("Allocated length: %d\n"), str.GetAllocLength());
str.Preallocate(100);
_tprintf_s(_T("Allocated length: %d\n"), str.GetAllocLength());
```
  
##  <a name="pxstr"></a>  CSimpleStringT::PXSTR  
Um ponteiro para uma cadeia de caracteres.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
typedef ChTraitsBase< BaseType >::PXSTR PXSTR;  
```  
##  <a name="releasebuffer"></a>  CSimpleStringT::ReleaseBuffer  
Libera o controle do buffer alocado pelo [GetBuffer](#getbuffer).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void ReleaseBuffer(int nNewLength = -1);
```  
#### <a name="parameters"></a>Parâmetros  
 `nNewLength`  
 O novo comprimento da cadeia de caracteres em caracteres, sem contar um terminador nulo. Se a cadeia de caracteres é terminada em nulo, define o valor padrão de-1 a `CSimpleStringT` tamanho para o comprimento atual da cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para realocar ou liberar o buffer do objeto de cadeia de caracteres. Se você souber que a cadeia de caracteres no buffer de terminação nula, você pode omitir o `nNewLength` argumento. Se a cadeia de caracteres não for nula terminada, use `nNewLength` para especificar seu comprimento. O endereço retornado por [GetBuffer](#getbuffer) é inválido após a chamada a `ReleaseBuffer` ou qualquer outro `CSimpleStringT` operação.  
  
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
  
##  <a name="releasebuffersetlength"></a>  CSimpleStringT::ReleaseBufferSetLength

Libera o controle do buffer alocado pelo [GetBuffer](#getbuffer).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void ReleaseBufferSetLength(int nNewLength);
```  
#### <a name="parameters"></a>Parâmetros  
 `nNewLength`  
 O comprimento da cadeia de caracteres que está sendo liberado  
  
### <a name="remarks"></a>Comentários  
 Essa função é funcionalmente semelhante a [ReleaseBuffer](#releasebuffer) exceto que um tamanho válido para o objeto de cadeia de caracteres deve ser passado.  
  
##  <a name="setat"></a>  CSimpleStringT::SetAt  
Define um único caractere de um `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void SetAt(int iChar, XCHAR ch);
```  
#### <a name="parameters"></a>Parâmetros  
 `iChar`  
 Índice de base zero do caractere de `CSimpleStringT` objeto. O `iChar` parâmetro deve ser maior que ou igual a 0 e menor que o valor retornado por [GetLength](#getlength).  
  
 *ch*  
 O caractere de nova.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para substituir o caractere localizado em `iChar`. Esse método não aumentará a cadeia de caracteres se `iChar` exceder os limites da cadeia de caracteres existente.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::SetAt`.  
  
```cpp  
CSimpleString s(_T("abcdef"), pMgr);
s.SetAt(1, _T('a'));
ASSERT(_tcscmp(s, _T("aacdef")) == 0);
``` 
  
##  <a name="setmanager"></a>  CSimpleStringT::SetManager  
Especifica o Gerenciador de memória do `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void SetManager(IAtlStringMgr* pStringMgr);
```  
#### <a name="parameters"></a>Parâmetros  
 `pStringMgr`  
 Um ponteiro para o novo Gerenciador de memória.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para especificar uma nova memória usado pelo Gerenciador do `CSimpleStringT` objeto. Para obter mais informações sobre gerenciadores de memória e objetos de cadeia de caracteres, consulte [gerenciamento de memória e CStringT](../memory-management-with-cstringt.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::SetManager`.  
  
```cpp  
CSimpleString s(pMgr);
s.SetManager(pCustomMgr);
```
  
##  <a name="setstring"></a>  CSimpleStringT::SetString  
Define a cadeia de caracteres de um `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void SetString(PCXSTR pszSrc, int nLength); 
void SetString(PCXSTR pszSrc);
```  
#### <a name="parameters"></a>Parâmetros  
 `pszSrc`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo.  
  
 `nLength`  
 Uma contagem do número de caracteres em `pszSrc`.  
  
### <a name="remarks"></a>Comentários  
 Copie uma cadeia de caracteres para o `CSimpleStringT` objeto. `SetString` substitui os dados mais antigos de cadeia de caracteres no buffer.  
  
 Ambas as versões do `SetString` Verifique se `pszSrc` é um ponteiro nulo e se for, gerará um **E_INVALIDARG** erro.  
  
 A versão de um parâmetro de `SetString` espera `pszSrc` para apontar para uma cadeia de caracteres terminada em nulo.  
  
 A versão de dois parâmetros de `SetString` também espera `pszSrc` para ser uma cadeia de caracteres terminada em nulo. Ele usa `nLength` como o comprimento da cadeia de caracteres, a menos que ele encontra um terminador nulo primeiro.  
  
 A versão de dois parâmetros de `SetString` também verifica se `pszSrc` aponta para um local no buffer atual em `CSimpleStringT`. Nesse caso especial, `SetString` usa uma função de cópia de memória que não substituirá os dados de cadeia de caracteres como ele copia os dados de cadeia de caracteres para o buffer.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::SetString`.  
  
```cpp  
CSimpleString s(_T("abcdef"), pMgr);
ASSERT(_tcscmp(s, _T("abcdef")) == 0);
s.SetString(_T("Soccer"), 6);
ASSERT(_tcscmp(s, _T("Soccer")) == 0);
```
  
##  <a name="stringlength"></a>  CSimpleStringT::StringLength  
Retorna o número de caracteres na cadeia de caracteres especificada.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ATL_NOINLINE static int StringLength(PCXSTR psz) throw();
```  
#### <a name="parameters"></a>Parâmetros  
 `psz`  
 Um ponteiro para uma cadeia de caracteres terminada em nulo.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres em `psz`; sem contar um terminador nulo.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar o número de caracteres na cadeia de caracteres apontada por `psz`.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso de `CSimpleStringT::StringLength`.  
  
```cpp  
ASSERT(CSimpleString::StringLength(_T("soccer")) == 6);
``` 
  
##  <a name="truncate"></a>  CSimpleStringT::Truncate
Trunca a cadeia de caracteres para o novo comprimento.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void Truncate(int nNewLength);
```  
#### <a name="parameters"></a>Parâmetros  
 `nNewLength`  
 O novo comprimento da cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para truncar o conteúdo da cadeia de caracteres para o novo comprimento.  
  
> [!NOTE]
>  Isso não afeta o tamanho alocado do buffer. Para reduzir ou aumentar o buffer atual, consulte [FreeExtra](#freeextra) e [Preallocate](#preallocate).  
  
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
  
##  <a name="unlockbuffer"></a>  CSimpleStringT::UnlockBuffer
 Desbloqueia o buffer do `CSimpleStringT` objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
void UnlockBuffer() throw();
```  
### <a name="remarks"></a>Comentários  
 Chame esse método para redefinir a contagem de referência da cadeia de caracteres como 1.  
  
 O `CSimpleStringT` destrutor chama automaticamente `UnlockBuffer` para garantir que o buffer não é bloqueado quando o destruidor é chamado. Para obter um exemplo desse método, consulte [LockBuffer](#lockbuffer).  
  
##  <a name="dtor"></a>  CSimpleStringT:: ~ CSimpleStringT
Destrói um objeto `CSimpleStringT`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
~CSimpleStringT() throw();
```  
### <a name="remarks"></a>Comentários  
 Chame este método para destruir o `CSimpleStringT` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes compartilhadas do ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)