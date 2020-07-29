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
ms.openlocfilehash: a435cf8e5501e4f21af53091dc0e28f1c1037379
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226562"
---
# <a name="ccomvariant-class"></a>Classe CComVariant

Essa classe encapsula o tipo VARIANT, fornecendo um membro que indica o tipo de dados armazenados.

## <a name="syntax"></a>Sintaxe

```cpp
class CComVariant : public tagVARIANT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComVariant::CComVariant](#ccomvariant)|O construtor.|
|[CComVariant:: ~ CComVariant](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComVariant:: Attach](#attach)|Anexa uma variante ao `CComVariant` objeto.|
|[CComVariant:: ChangeType](#changetype)|Converte o `CComVariant` objeto em um novo tipo.|
|[CComVariant:: Clear](#clear)|Limpa o `CComVariant` objeto.|
|[CComVariant:: copiar](#copy)|Copia uma variante para o `CComVariant` objeto.|
|[CComVariant:: CopyTo](#copyto)|Copia o conteúdo do `CComVariant` objeto.|
|[CComVariant::D Etach](#detach)|Desanexa a variante subjacente do `CComVariant` objeto.|
|[CComVariant::GetSize](#getsize)|Retorna o tamanho em número de bytes do conteúdo do `CComVariant` objeto.|
|[CComVariant::ReadFromStream](#readfromstream)|Carrega uma variante de um fluxo.|
|[CComVariant:: SetByRef](#setbyref)|Inicializa o `CComVariant` objeto e define o `vt` membro como VT_BYREF.|
|[CComVariant::WriteToStream](#writetostream)|Salva a variante subjacente em um fluxo.|

### <a name="public-operators"></a>Operadores públicos

|||
|-|-|
|[Operador CComVariant:: Operator <](#operator_lt)|Indica se o `CComVariant` objeto é menor que a variante especificada.|
|[Operador CComVariant:: Operator >](#operator_gt)|Indica se o `CComVariant` objeto é maior que a variante especificada.|
|[operador! =](#operator_neq)|Indica se o `CComVariant` objeto não é igual à variante especificada.|
|[operador =](#operator_eq)|Atribui um valor ao `CComVariant` objeto.|
|[operador = =](#operator_eq_eq)|Indica se o `CComVariant` objeto é igual à variante especificada.|

## <a name="remarks"></a>Comentários

`CComVariant`encapsula a variante e o tipo VARIANTARG, que consiste em uma União e um membro que indica o tipo dos dados armazenados na União. As VARIAntes são normalmente usadas na automação.

`CComVariant`deriva do tipo VARIANT para que ele possa ser usado onde for possível usar uma variante. Você pode, por exemplo, usar a macro V_VT para extrair o tipo de um `CComVariant` ou você pode acessar o `vt` membro diretamente, exatamente como é possível com uma variante.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagVARIANT`

`CComVariant`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

## <a name="ccomvariantattach"></a><a name="attach"></a>CComVariant:: Attach

Limpa com segurança o conteúdo atual do `CComVariant` objeto, copia o conteúdo de *pSrc* para esse objeto e, em seguida, define o tipo de variante de *pSrc* como VT_EMPTY.

```
HRESULT Attach(VARIANT* pSrc);
```

### <a name="parameters"></a>parâmetros

*pSrc*<br/>
no Aponta para a [variante](/windows/win32/api/oaidl/ns-oaidl-variant) a ser anexada ao objeto.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A propriedade dos dados mantidos pelo *pSrc* é transferida para o `CComVariant` objeto.

## <a name="ccomvariantccomvariant"></a><a name="ccomvariant"></a>CComVariant::CComVariant

Cada Construtor manipula a inicialização segura do `CComVariant` objeto chamando a função do `VariantInit` Win32 ou definindo o valor e o tipo do objeto de acordo com os parâmetros passados.

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

### <a name="parameters"></a>parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
no A `CComVariant` variante ou usada para inicializar o `CComVariant` objeto. O conteúdo da variante de origem é copiado para o destino sem conversão.

*lpszSrc*<br/>
no A cadeia de caracteres usada para inicializar o `CComVariant` objeto. Você pode passar uma cadeia de caracteres Unicode (Wide-terminada) com final de zero para a versão LPCOLESTR do construtor ou uma cadeia de caracteres ANSI para a versão LPCSTR. Em ambos os casos, a cadeia de caracteres é convertida em um BSTR Unicode alocado usando `SysAllocString` . O tipo do `CComVariant` objeto será VT_BSTR.

*bSrc*<br/>
no O **`bool`** usado para inicializar o `CComVariant` objeto. O **`bool`** argumento é convertido em um VARIANT_BOOL antes de ser armazenado. O tipo do `CComVariant` objeto será VT_BOOL.

*nSrc*<br/>
no O **`int`** , **byte**, **`short`** , **`long`** , LONGLONG, ULONGLONG, **`unsigned short`** , **`unsigned long`** ou **`unsigned int`** usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_I4, VT_UI1, VT_I2, VT_I4, VT_I8, VT_UI8, VT_UI2, VT_UI4 ou VT_UI4, respectivamente.

*vtSrc*<br/>
no O tipo da variante. Quando o primeiro parâmetro é **`int`** , os tipos válidos são VT_I4 e VT_INT. Quando o primeiro parâmetro é **`long`** , os tipos válidos são VT_I4 e VT_ERROR. Quando o primeiro parâmetro é **`double`** , os tipos válidos são VT_R8 e VT_DATE. Quando o primeiro parâmetro é **`unsigned int`** , os tipos válidos são VT_UI4 e VT_UINT.

*fltSrc*<br/>
no O **`float`** usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_R4.

*dblSrc*<br/>
no O **`double`** usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_R8.

*cySrc*<br/>
no O `CY` usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_CY.

*pSrc*<br/>
no O `IDispatch` `IUnknown` ponteiro ou usado para inicializar o `CComVariant` objeto. `AddRef`será chamado no ponteiro de interface. O tipo do `CComVariant` objeto será VT_DISPATCH ou VT_UNKNOWN, respectivamente.

Ou, o ponteiro SAFERRAY usado para inicializar o `CComVariant` objeto. Uma cópia do SAFEARRAY é armazenada no `CComVariant` objeto. O tipo do `CComVariant` objeto será uma combinação do tipo original de SafeArray e VT_ARRAY.

*cSrc*<br/>
no O **`char`** usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_I1.

*bstrSrc*<br/>
no O BSTR usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_BSTR.

### <a name="remarks"></a>Comentários

O destruidor gerencia a limpeza chamando [CComVariant:: Clear](#clear).

## <a name="ccomvariantccomvariant"></a><a name="dtor"></a>CComVariant:: ~ CComVariant

O destruidor.

```
~CComVariant() throw();
```

### <a name="remarks"></a>Comentários

Esse método gerencia a limpeza chamando [CComVariant:: Clear](#clear).

## <a name="ccomvariantchangetype"></a><a name="changetype"></a>CComVariant:: ChangeType

Converte o `CComVariant` objeto em um novo tipo.

```
HRESULT ChangeType(VARTYPE vtNew, const VARIANT* pSrc = NULL);
```

### <a name="parameters"></a>parâmetros

*vtNew*<br/>
no O novo tipo para o `CComVariant` objeto.

*pSrc*<br/>
no Um ponteiro para a variante cujo valor será convertido para o novo tipo. O valor padrão é NULL, o que significa que o `CComVariant` objeto será convertido em vigor.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se você passar um valor para *pSrc*, `ChangeType` o usará essa variante como a origem da conversão. Caso contrário, o `CComVariant` objeto será a origem.

## <a name="ccomvariantclear"></a><a name="clear"></a>CComVariant:: Clear

Limpa o `CComVariant` objeto chamando a função do `VariantClear` Win32.

```
HRESULT Clear();
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O destruidor chama automaticamente `Clear` .

## <a name="ccomvariantcopy"></a><a name="copy"></a>CComVariant:: copiar

Libera o `CComVariant` objeto e, em seguida, atribui a ele uma cópia da variante especificada.

```
HRESULT Copy(const VARIANT* pSrc);
```

### <a name="parameters"></a>parâmetros

*pSrc*<br/>
no Um ponteiro para a [variante](/windows/win32/api/oaidl/ns-oaidl-variant) a ser copiada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccomvariantcopyto"></a><a name="copyto"></a>CComVariant:: CopyTo

Copia o conteúdo do `CComVariant` objeto.

```
HRESULT CopyTo(BSTR* pstrDest);
```

### <a name="parameters"></a>parâmetros

*pstrDest*<br/>
Aponta para um BSTR que receberá uma cópia do conteúdo do `CComVariant` objeto.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O `CComVariant` objeto deve ser do tipo VT_BSTR.

## <a name="ccomvariantdetach"></a><a name="detach"></a>CComVariant::D Etach

Desanexa a variante subjacente do `CComVariant` objeto e define o tipo do objeto como VT_EMPTY.

```
HRESULT Detach(VARIANT* pDest);
```

### <a name="parameters"></a>parâmetros

*pDest*<br/>
fora Retorna o valor da variante subjacente do objeto.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Observe que o conteúdo da variante referenciada por *pDest* será automaticamente limpo antes de receber o valor e o tipo do objeto de chamada `CComVariant` .

## <a name="ccomvariantgetsize"></a><a name="getsize"></a>CComVariant::GetSize

Para VARIAntes de tamanho fixo simples, esse método retorna o **`sizeof`** valor para o tipo de dados subjacente, mais **sizeof (VARTYPE)**.

```
ULONG GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho em bytes do conteúdo atual do `CComVariant` objeto.

### <a name="remarks"></a>Comentários

Se a variante contiver um ponteiro de interface, `GetSize` consultas para `IPersistStream` ou `IPersistStreamInit` . Se for bem-sucedido, o valor de retorno será a ordem baixa de 32 bits do valor retornado por `GetSizeMax` Plus `sizeof(CLSID)` e `sizeof(VARTYPE)` . Se o ponteiro de interface for nulo, `GetSize` retornará `sizeof(CLSID)` mais `sizeof(VARTYPE)` . Se o tamanho total for maior que ULONG_MAX, o `GetSize` retornará `sizeof(VARTYPE)` que indica um erro.

Em todos os outros casos, uma variante temporária do tipo VT_BSTR é forçada da variante atual. O comprimento desse BSTR é calculado como o tamanho do comprimento da cadeia de caracteres mais o comprimento da cadeia de caracteres, mais o tamanho do caractere nulo mais **sizeof (VARTYPE)**. Se a variante não puder ser forçada a uma variante do tipo VT_BSTR, `GetSize` retornará **sizeof (VARTYPE)**.

O tamanho retornado por esse método corresponde ao número de bytes usados por [CComVariant:: WriteToStream](#writetostream) sob condições bem-sucedidas.

## <a name="ccomvariantoperator-"></a><a name="operator_eq"></a>CComVariant:: Operator =

Atribui um valor e o tipo correspondente ao `CComVariant` objeto.

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

### <a name="parameters"></a>parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
no A `CComVariant` [variante](/windows/win32/api/oaidl/ns-oaidl-variant) ou a ser atribuída ao `CComVariant` objeto. O conteúdo da variante de origem é copiado para o destino sem conversão.

*bstrSrc*<br/>
no O BSTR a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_BSTR.

*lpszSrc*<br/>
no A cadeia de caracteres a ser atribuída ao `CComVariant` objeto. Você pode passar uma cadeia de caracteres de caractere de largura zero (Unicode) para a versão LPCOLESTR do operador ou de uma cadeia de caracteres ANSI para a versão LPCSTR. Em ambos os casos, a cadeia de caracteres é convertida em um BSTR Unicode alocado usando `SysAllocString` . O tipo do `CComVariant` objeto será VT_BSTR.

*bSrc*<br/>
no O **`bool`** a ser atribuído ao `CComVariant` objeto. O **`bool`** argumento é convertido em um VARIANT_BOOL antes de ser armazenado. O tipo do `CComVariant` objeto será VT_BOOL.

*nSrc*<br/>
no O **`int`** , byte, **`short`** , **`long`** , LONGLONG, ULONGLONG, **`unsigned short`** , **`unsigned long`** ou **`unsigned int`** a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_I4, VT_UI1, VT_I2, VT_I4, VT_I8, VT_UI8, VT_UI2, VT_UI4 ou VT_UI4, respectivamente.

*fltSrc*<br/>
no O **`float`** a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_R4.

*dblSrc*<br/>
no O **`double`** a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_R8.

*cySrc*<br/>
no O `CY` a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_CY.

*pSrc*<br/>
no O `IDispatch` `IUnknown` ponteiro ou a ser atribuído ao `CComVariant` objeto. `AddRef`será chamado no ponteiro de interface. O tipo do `CComVariant` objeto será VT_DISPATCH ou VT_UNKNOWN, respectivamente.

Ou, um ponteiro SAFEARRAY a ser atribuído ao `CComVariant` objeto. Uma cópia do SAFEARRAY é armazenada no `CComVariant` objeto. O tipo do `CComVariant` objeto será uma combinação do tipo original de SafeArray e VT_ARRAY.

*cSrc*<br/>
no O caractere a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_I1.

## <a name="ccomvariantoperator-"></a><a name="operator_eq_eq"></a>CComVariant:: Operator = =

Indica se o `CComVariant` objeto é igual à variante especificada.

```
bool operator==(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retorna TRUE se o valor e o tipo de *varSrc* são iguais ao valor e ao tipo, respectivamente, do `CComVariant` objeto. Caso contrário, FALSE. O operador usa a localidade padrão do usuário para executar a comparação.

O operador compara somente o valor dos tipos variantes. Ele compara Cadeias de caracteres, inteiros e pontos flutuantes, mas não matrizes ou registros.

## <a name="ccomvariantoperator-"></a><a name="operator_neq"></a>CComVariant:: Operator! =

Indica se o `CComVariant` objeto não é igual à variante especificada.

```
bool operator!=(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retornará TRUE se o valor ou o tipo de *varSrc* não for igual ao valor ou tipo, respectivamente, do `CComVariant` objeto. Caso contrário, FALSE. O operador usa a localidade padrão do usuário para executar a comparação.

O operador compara somente o valor dos tipos variantes. Ele compara Cadeias de caracteres, inteiros e pontos flutuantes, mas não matrizes ou registros.

## <a name="ccomvariantoperator-lt"></a><a name="operator_lt"></a>Operador CComVariant::&lt;

Indica se o `CComVariant` objeto é menor que a variante especificada.

```
bool operator<(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retornará TRUE se o valor do `CComVariant` objeto for menor que o valor de *varSrc*. Caso contrário, FALSE. O operador usa a localidade padrão do usuário para executar a comparação.

## <a name="ccomvariantoperator-gt"></a><a name="operator_gt"></a>Operador CComVariant::&gt;

Indica se o `CComVariant` objeto é maior que a variante especificada.

```
bool operator>(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retornará TRUE se o valor do `CComVariant` objeto for maior que o valor de *varSrc*. Caso contrário, FALSE. O operador usa a localidade padrão do usuário para executar a comparação.

## <a name="ccomvariantreadfromstream"></a><a name="readfromstream"></a>CComVariant::ReadFromStream

Define a variante subjacente para a variante contida no fluxo especificado.

```
HRESULT ReadFromStream(IStream* pStream);
```

### <a name="parameters"></a>parâmetros

*pStream*<br/>
no Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) no fluxo que contém os dados.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

`ReadToStream`requer uma chamada anterior para [WriteToStream](#writetostream).

## <a name="ccomvariantsetbyref"></a><a name="setbyref"></a>CComVariant:: SetByRef

Inicializa o `CComVariant` objeto e define o `vt` membro como VT_BYREF.

```
template < typename T >
void SetByRef(T* pT) throw();
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de variante, por exemplo, BSTR, **`int`** ou **`char`** .

*pT*<br/>
O ponteiro usado para inicializar o `CComVariant` objeto.

### <a name="remarks"></a>Comentários

`SetByRef`é um modelo de função que inicializa o `CComVariant` objeto para o ponteiro *pt* e define o `vt` membro como VT_BYREF. Por exemplo:

[!code-cpp[NVC_ATL_Utilities#76](../../atl/codesnippet/cpp/ccomvariant-class_1.cpp)]

## <a name="ccomvariantwritetostream"></a><a name="writetostream"></a>CComVariant::WriteToStream

Salva a variante subjacente em um fluxo.

```
HRESULT WriteToStream(IStream* pStream);
```

### <a name="parameters"></a>parâmetros

*pStream*<br/>
no Um ponteiro para a interface [IStream](/windows/win32/api/objidl/nn-objidl-istream) em um fluxo.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
