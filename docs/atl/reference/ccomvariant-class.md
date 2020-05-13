---
title: Classe CComVariant
ms.date: 11/04/2016
f1_keywords:
- CComVariant
- ATLCOMCLI/ATL::CComVariant
- ATLCOMCLI/ATL::CComVariant::CComVariant
- ATLCOMCLI/ATL::CComVariant::Attach
- ATLCOMCLI/ATL::CComVariant::ChangeType
- ATLCOMCLI/ATL::CComVariant::Clear
- ATLCOMCLI/ATL::CComVariant::Copy
- ATLCOMCLI/ATL::CComVariant::CopyTo
- ATLCOMCLI/ATL::CComVariant::Detach
- ATLCOMCLI/ATL::CComVariant::GetSize
- ATLCOMCLI/ATL::CComVariant::ReadFromStream
- ATLCOMCLI/ATL::CComVariant::SetByRef
- ATLCOMCLI/ATL::CComVariant::WriteToStream
helpviewer_keywords:
- VARIANT macro
- CComVariant class
- VARIANT macro, ATL
ms.assetid: 4d31149c-d005-44b5-a509-10f84afa2b61
ms.openlocfilehash: 9a84d91e20242fb206d1d3f71fcb3dd207561f62
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327221"
---
# <a name="ccomvariant-class"></a>Classe CComVariant

Esta classe envolve o tipo VARIANT, fornecendo um membro indicando o tipo de dados armazenados.

## <a name="syntax"></a>Sintaxe

```cpp
class CComVariant : public tagVARIANT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComVariant::CComVariant](#ccomvariant)|O construtor.|
|[CComVariant::~CComVariant](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComVariant::Anexar](#attach)|Anexa uma VARIANT `CComVariant` ao objeto.|
|[CComVariant::ChangeType](#changetype)|Converte `CComVariant` o objeto em um novo tipo.|
|[CComVariant::Clear](#clear)|Limpa o `CComVariant` objeto.|
|[CComVariant::Copiar](#copy)|Copia uma VARIANT `CComVariant` para o objeto.|
|[CComVariant::CopyTo](#copyto)|Copia o conteúdo `CComVariant` do objeto.|
|[CComVariant::Detach](#detach)|Destaca a VARIANTE subjacente `CComVariant` do objeto.|
|[CComVariant::GetSize](#getsize)|Retorna o tamanho em número de bytes do conteúdo do `CComVariant` objeto.|
|[CComVariant::ReadFromStream](#readfromstream)|Carrega uma VARIANTE de um fluxo.|
|[CComVariant::SetbyRef](#setbyref)|Inicializa o `CComVariant` objeto e `vt` define o membro para VT_BYREF.|
|[CComVariant::WriteToStream](#writetostream)|Salva a VARIANT subjacente a um fluxo.|

### <a name="public-operators"></a>Operadores públicos

|||
|-|-|
|[CComVariant::<do operador](#operator_lt)|Indica se `CComVariant` o objeto é menor que o VARIANT especificado.|
|[CComVariant::>do operador](#operator_gt)|Indica se `CComVariant` o objeto é maior que a VARIANTespecificada.|
|[operador !=](#operator_neq)|Indica se `CComVariant` o objeto não é igual à VARIANTe especificada.|
|[operador =](#operator_eq)|Atribui um valor `CComVariant` ao objeto.|
|[operador ==](#operator_eq_eq)|Indica se `CComVariant` o objeto é igual ao VARIANT especificado.|

## <a name="remarks"></a>Comentários

`CComVariant`envolve o tipo VARIANT e VARIANTARG, que consiste em uma união e um membro indicando o tipo de dados armazenados na união. Variants são normalmente usados em Automação.

`CComVariant`deriva do tipo VARIANT para que possa ser usado onde quer que uma VARIANT possa ser usada. Você pode, por exemplo, usar a V_VT `CComVariant` macro para extrair `vt` o tipo de a ou você pode acessar o membro diretamente como você pode com uma VARIANT.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagVARIANT`

`CComVariant`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli.h

## <a name="ccomvariantattach"></a><a name="attach"></a>CComVariant::Anexar

Limpa com segurança o conteúdo `CComVariant` atual do objeto, copia o conteúdo do *pSrc* para este objeto e define o tipo variante de *pSrc* para VT_EMPTY.

```
HRESULT Attach(VARIANT* pSrc);
```

### <a name="parameters"></a>Parâmetros

*Psrc*<br/>
[em] Aponta para a [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) a ser anexada ao objeto.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A propriedade dos dados mantidos pelo `CComVariant` *pSrc* é transferida para o objeto.

## <a name="ccomvariantccomvariant"></a><a name="ccomvariant"></a>CComVariant::CComVariant

Cada construtor lida com a inicialização segura do `CComVariant` objeto chamando a `VariantInit` função Win32 ou definindo o valor e o tipo do objeto de acordo com os parâmetros passados.

```
CComVariant() throw();
CComVariant(const CComVariant& varSrc);
CComVariant(const VARIANT& varSrc);
CComVariant(LPCOLESTR lpszSrc);
CComVariant(LPCSTR lpszSrc);
CComVariant(bool bSrc);
CComVariant(BYTE nSrc) throw();
CComVariant(int nSrc, VARTYPE vtSrc = VT_I4) throw();
CComVariant(unsigned int  nSrc, VARTYPE vtSrc = VT_UI4) throw();
CComVariant(shor  nSrc) throw();
CComVariant(unsigned short nSrc) throw();
CComVariant(long  nSrc, VARTYPE vtSrc = VT_I4) throw();
CComVariant(unsigned long  nSrc) throw();
CComVariant(LONGLONG  nSrc) throw();
CComVariant(ULONGLONG  nSrc) throw();
CComVariant(float  fltSrc) throw();
CComVariant(double  dblSrc, VARTYPE vtSrc = VT_R8) throw();
CComVariant(CY  cySrc) throw();
CComVariant(IDispatch* pSrc) throw();
CComVariant(IUnknown* pSrc) throw();
CComVariant(const SAFEARRAY* pSrc);
CComVariant(char  cSrc) throw();
CComVariant(const CComBSTR& bstrSrc);
```

### <a name="parameters"></a>Parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
[em] O `CComVariant` ou VARIANT usado `CComVariant` para inicializar o objeto. O conteúdo da variante de origem é copiado para o destino sem conversão.

*lpszSrc*<br/>
[em] A seqüência de `CComVariant` caracteres usada para inicializar o objeto. Você pode passar uma seqüência de caracteres de largura com término zero (Unicode) para a versão LPCOLESTR do construtor ou uma seqüência ANSI para a versão LPCSTR. Em ambos os casos, a seqüência é `SysAllocString`convertida em um Unicode BSTR alocado usando . O tipo `CComVariant` do objeto será VT_BSTR.

*bSrc*<br/>
[em] O **bool** usado para `CComVariant` inicializar o objeto. O argumento **bool** é convertido em um VARIANT_BOOL antes de ser armazenado. O tipo `CComVariant` do objeto será VT_BOOL.

*Nsrc*<br/>
[em] Int , **BYTE**, **curto**, **longo**, LONGLONG, ULONGLONG, **curto não assinado,** longo `CComVariant` não **assinado,** ou **int não assinado** usado para inicializar o objeto. **int** O tipo `CComVariant` de objeto será VT_I4, VT_UI1, VT_I2, VT_I4, VT_I8, VT_UI8, VT_UI2, VT_UI4 ou VT_UI4, respectivamente.

*Vtsrc*<br/>
[em] O tipo da variante. Quando o primeiro parâmetro é **int,** os tipos válidos são VT_I4 e VT_INT. Quando o primeiro parâmetro é **longo,** os tipos válidos são VT_I4 e VT_ERROR. Quando o primeiro parâmetro é **duplo,** os tipos válidos são VT_R8 e VT_DATE. Quando o primeiro parâmetro **é int não assinado,** os tipos válidos são VT_UI4 e VT_UINT.

*fltSrc*<br/>
[em] O **carro alegórico** usado `CComVariant` para inicializar o objeto. O tipo `CComVariant` do objeto será VT_R4.

*dblSrc*<br/>
[em] O **duplo** usado para `CComVariant` inicializar o objeto. O tipo `CComVariant` do objeto será VT_R8.

*cisrc*<br/>
[em] O `CY` usado para `CComVariant` inicializar o objeto. O tipo `CComVariant` do objeto será VT_CY.

*Psrc*<br/>
[em] O `IDispatch` `IUnknown` ponteiro usado para `CComVariant` inicializar o objeto. `AddRef`será chamado no ponteiro de interface. O tipo `CComVariant` do objeto será VT_DISPATCH ou VT_UNKNOWN, respectivamente.

Ou, o ponteiro SAFERRAY usado `CComVariant` para inicializar o objeto. Uma cópia do SAFEARRAY é `CComVariant` armazenada no objeto. O tipo `CComVariant` do objeto será uma combinação do tipo original do SAFEARRAY e VT_ARRAY.

*Csrc*<br/>
[em] O **char** usado para `CComVariant` inicializar o objeto. O tipo `CComVariant` do objeto será VT_I1.

*bstrSrc*<br/>
[em] O BSTR usado para `CComVariant` inicializar o objeto. O tipo `CComVariant` do objeto será VT_BSTR.

### <a name="remarks"></a>Comentários

O destruidor gerencia a limpeza ligando para [CComVariant:::Clear](#clear).

## <a name="ccomvariantccomvariant"></a><a name="dtor"></a>CComVariant::~CComVariant

O destruidor.

```
~CComVariant() throw();
```

### <a name="remarks"></a>Comentários

Este método gerencia a limpeza chamando [CComVariant::Clear](#clear).

## <a name="ccomvariantchangetype"></a><a name="changetype"></a>CComVariant::ChangeType

Converte `CComVariant` o objeto em um novo tipo.

```
HRESULT ChangeType(VARTYPE vtNew, const VARIANT* pSrc = NULL);
```

### <a name="parameters"></a>Parâmetros

*vtNew*<br/>
[em] O novo tipo `CComVariant` para o objeto.

*Psrc*<br/>
[em] Um ponteiro para a VARIANT cujo valor será convertido para o novo tipo. O valor padrão é `CComVariant` NULL, o que significa que o objeto será convertido no lugar.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se você passar um valor `ChangeType` para *pSrc,* usará esta VARIANT como fonte para a conversão. Caso contrário, `CComVariant` o objeto será a fonte.

## <a name="ccomvariantclear"></a><a name="clear"></a>CComVariant::Clear

Limpa o `CComVariant` objeto chamando a `VariantClear` função Win32.

```
HRESULT Clear();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O destruidor chama `Clear`automaticamente.

## <a name="ccomvariantcopy"></a><a name="copy"></a>CComVariant::Copiar

Libera o `CComVariant` objeto e, em seguida, atribui-o uma cópia da VARIANT especificada.

```
HRESULT Copy(const VARIANT* pSrc);
```

### <a name="parameters"></a>Parâmetros

*Psrc*<br/>
[em] Um ponteiro para a [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) a ser copiado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccomvariantcopyto"></a><a name="copyto"></a>CComVariant::CopyTo

Copia o conteúdo `CComVariant` do objeto.

```
HRESULT CopyTo(BSTR* pstrDest);
```

### <a name="parameters"></a>Parâmetros

*pstrDest*<br/>
Aponta para um BSTR que receberá uma `CComVariant` cópia do conteúdo do objeto.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O `CComVariant` objeto deve ser de tipo VT_BSTR.

## <a name="ccomvariantdetach"></a><a name="detach"></a>CComVariant::Detach

Destaca a VARIANTE subjacente `CComVariant` do objeto e define o tipo do objeto para VT_EMPTY.

```
HRESULT Detach(VARIANT* pDest);
```

### <a name="parameters"></a>Parâmetros

*pDest*<br/>
[fora] Retorna o valor VARIANT subjacente do objeto.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Observe que o conteúdo da VARIANT referenciada pelo *pDest* será automaticamente limpo antes `CComVariant` de ser atribuído o valor e o tipo do objeto de chamada.

## <a name="ccomvariantgetsize"></a><a name="getsize"></a>CComVariant::GetSize

Para VARIANTs de tamanho simples, este método retorna o **tamanho do** tipo de dados subjacente mais **tamanho (VARTYPE)**.

```
ULONG GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho em bytes do `CComVariant` conteúdo atual do objeto.

### <a name="remarks"></a>Comentários

Se a VARIANT contiver `GetSize` um `IPersistStream` ponteiro `IPersistStreamInit`de interface, consultas para ou . Se for bem-sucedido, o valor de retorno é o `GetSizeMax` valor de 32 bits de baixa ordem do valor devolvido por mais o **tamanho de** um CLSID e **tamanho (VARTYPE)**. Se o ponteiro da `GetSize` interface for NULO, retorne o **tamanho de** um CLSID plus **sizeof (VARTYPE)**. Se o tamanho total for `GetSize` maior que ULONG_MAX, retorna **tamanho (VARTYPE)** que indica um erro.

Em todos os outros casos, uma variante temporária do tipo VT_BSTR é coavida da VARIANT atual. O comprimento deste BSTR é calculado como o tamanho do comprimento da seqüência mais o comprimento da seqüência em si mais o tamanho do caractere nulo mais **tamanho (VARTYPE)**. Se a VARIANT não puder ser coavida `GetSize` para uma variante do tipo VT_BSTR, retorne **tamanho (VARTYPE)**.

O tamanho retornado por este método corresponde ao número de bytes usados por [CComVariant::WriteToStream](#writetostream) em condições bem sucedidas.

## <a name="ccomvariantoperator-"></a><a name="operator_eq"></a>CComVariant::operador =

Atribui um valor e um `CComVariant` tipo correspondente ao objeto.

```
CComVariant& operator=(const CComVariant& varSrc);
CComVariant& operator=(const VARIANT& varSrc);
CComVariant& operator=(const CComBSTR& bstrSrc);
CComVariant& operator=(LPCOLESTR lpszSrc);
CComVariant& operator=(LPCSTR lpszSrc);
CComVariant& operator=(bool bSrc);
CComVariant& operator=(BYTE nSrc) throw();
CComVariant& operator=int nSrc) throw();
CComVariant& operator=(unsigned int nSrc) throw();
CComVariant& operator=(short nSrc) throw();
CComVariant& operator=(unsigned short nSrc) throw();
CComVariant& operator=(long nSrc) throw();
CComVariant& operator=(unsigned long nSrc) throw();
CComVariant& operator=(LONGLONG nSrc) throw();
CComVariant& operator=(ULONGLONG nSrc) throw();
CComVariant& operator=(float fltSrc) throw();
CComVariant& operator=(double dblSrc) throw();
CComVariant& operator=(CY cySrc) throw();
CComVariant& operator=(IDispatch* pSrc) throw();
CComVariant& operator=(IUnknown* pSrc) throw();
CComVariant& operator=(const SAFEARRAY* pSrc);
CComVariant& operator=(char cSrc) throw();
```

### <a name="parameters"></a>Parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
[em] O `CComVariant` OU [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) a ser `CComVariant` atribuído ao objeto. O conteúdo da variante de origem é copiado para o destino sem conversão.

*bstrSrc*<br/>
[em] O BSTR a ser `CComVariant` atribuído ao objeto. O tipo `CComVariant` do objeto será VT_BSTR.

*lpszSrc*<br/>
[em] A seqüência de caracteres a ser atribuída ao `CComVariant` objeto. Você pode passar uma seqüência de caracteres de largura com término zero (Unicode) para a versão LPCOLESTR do operador ou uma seqüência ANSI para a versão LPCSTR. Em ambos os casos, a seqüência é convertida `SysAllocString`em um Unicode BSTR alocado usando . O tipo `CComVariant` do objeto será VT_BSTR.

*bSrc*<br/>
[em] O **bool** a ser `CComVariant` atribuído ao objeto. O argumento **bool** é convertido em um VARIANT_BOOL antes de ser armazenado. O tipo `CComVariant` do objeto será VT_BOOL.

*Nsrc*<br/>
[em] Int , BYTE, **curto**, **longo**, LONGLONG, ULONGLONG, **curto não assinado,** longo não `CComVariant` **assinado,** ou **int não assinado** a ser atribuído ao objeto. **int** O tipo `CComVariant` de objeto será VT_I4, VT_UI1, VT_I2, VT_I4, VT_I8, VT_UI8, VT_UI2, VT_UI4 ou VT_UI4, respectivamente.

*fltSrc*<br/>
[em] O **carro alegórico** a `CComVariant` ser atribuído ao objeto. O tipo `CComVariant` do objeto será VT_R4.

*dblSrc*<br/>
[em] O **duplo** a ser `CComVariant` atribuído ao objeto. O tipo `CComVariant` do objeto será VT_R8.

*cisrc*<br/>
[em] O `CY` a ser atribuído `CComVariant` ao objeto. O tipo `CComVariant` do objeto será VT_CY.

*Psrc*<br/>
[em] O `IDispatch` `IUnknown` ponteiro a ser atribuído `CComVariant` ao objeto. `AddRef`será chamado no ponteiro de interface. O tipo `CComVariant` do objeto será VT_DISPATCH ou VT_UNKNOWN, respectivamente.

Ou, um ponteiro SAFEARRAY a `CComVariant` ser atribuído ao objeto. Uma cópia do SAFEARRAY é `CComVariant` armazenada no objeto. O tipo `CComVariant` do objeto será uma combinação do tipo original do SAFEARRAY e VT_ARRAY.

*Csrc*<br/>
[em] O char a ser `CComVariant` atribuído ao objeto. O tipo `CComVariant` do objeto será VT_I1.

## <a name="ccomvariantoperator-"></a><a name="operator_eq_eq"></a>CComVariant::operador ==

Indica se `CComVariant` o objeto é igual ao VARIANT especificado.

```
bool operator==(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retorna TRUE se o valor e o tipo de *varSrc* forem `CComVariant` iguais ao valor e tipo, respectivamente, do objeto. Caso contrário, FALSE. O operador usa o local padrão do usuário para realizar a comparação.

O operador compara apenas o valor dos tipos de variantes. Ele compara strings, inteiros e pontos flutuantes, mas não matrizes ou registros.

## <a name="ccomvariantoperator-"></a><a name="operator_neq"></a>CComVariant::operador !=

Indica se `CComVariant` o objeto não é igual à VARIANTe especificada.

```
bool operator!=(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retorna TRUE se o valor ou o tipo de *varSrc* não for `CComVariant` igual ao valor ou tipo, respectivamente, do objeto. Caso contrário, FALSE. O operador usa o local padrão do usuário para realizar a comparação.

O operador compara apenas o valor dos tipos de variantes. Ele compara strings, inteiros e pontos flutuantes, mas não matrizes ou registros.

## <a name="ccomvariantoperator-lt"></a><a name="operator_lt"></a>CComVariant::operador&lt;

Indica se `CComVariant` o objeto é menor que o VARIANT especificado.

```
bool operator<(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retorna TRUE se o `CComVariant` valor do objeto for menor que o valor do *varSrc*. Caso contrário, FALSE. O operador usa o local padrão do usuário para realizar a comparação.

## <a name="ccomvariantoperator-gt"></a><a name="operator_gt"></a>CComVariant::operador&gt;

Indica se `CComVariant` o objeto é maior que a VARIANTespecificada.

```
bool operator>(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retorna TRUE se o `CComVariant` valor do objeto for maior que o valor do *varSrc*. Caso contrário, FALSE. O operador usa o local padrão do usuário para realizar a comparação.

## <a name="ccomvariantreadfromstream"></a><a name="readfromstream"></a>CComVariant::ReadFromStream

Define a VARIANT subjacente à VARIANT contida no fluxo especificado.

```
HRESULT ReadFromStream(IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
[em] Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) no fluxo que contém os dados.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`ReadToStream`requer uma chamada anterior para [WriteToStream](#writetostream).

## <a name="ccomvariantsetbyref"></a><a name="setbyref"></a>CComVariant::SetbyRef

Inicializa o `CComVariant` objeto e `vt` define o membro para VT_BYREF.

```
template < typename T >
void SetByRef(T* pT) throw();
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de VARIANT, por exemplo, BSTR, **int**, ou **char**.

*pT*<br/>
O ponteiro usado para `CComVariant` inicializar o objeto.

### <a name="remarks"></a>Comentários

`SetByRef`é um modelo de função `CComVariant` que inicializa o objeto `vt` para o ponteiro *pT* e define o membro para VT_BYREF. Por exemplo:

[!code-cpp[NVC_ATL_Utilities#76](../../atl/codesnippet/cpp/ccomvariant-class_1.cpp)]

## <a name="ccomvariantwritetostream"></a><a name="writetostream"></a>CComVariant::WriteToStream

Salva a VARIANT subjacente a um fluxo.

```
HRESULT WriteToStream(IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
[em] Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) em um fluxo.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
