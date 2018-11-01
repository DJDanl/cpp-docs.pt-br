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
ms.openlocfilehash: dd53bdea211610b208516860b29c1b0094f5a4da
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523260"
---
# <a name="ccomvariant-class"></a>Classe CComVariant

Essa classe encapsula o tipo de VARIANTE, fornecendo um membro que indica o tipo de dados armazenados.

## <a name="syntax"></a>Sintaxe

```cpp
class CComVariant : public tagVARIANT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComVariant::CComVariant](#ccomvariant)|O construtor.|
|[CComVariant:: ~ CComVariant](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComVariant::Attach](#attach)|Anexa uma VARIANTE para o `CComVariant` objeto.|
|[CComVariant::ChangeType](#changetype)|Converte o `CComVariant` objeto para um novo tipo.|
|[CComVariant::Clear](#clear)|Limpa o `CComVariant` objeto.|
|[CComVariant::Copy](#copy)|Copia uma VARIANTE para o `CComVariant` objeto.|
|[CComVariant::CopyTo](#copyto)|Copia o conteúdo do `CComVariant` objeto.|
|[CComVariant::Detach](#detach)|Desanexa a VARIANTE subjacente do `CComVariant` objeto.|
|[CComVariant::GetSize](#getsize)|Retorna o tamanho em número de bytes do conteúdo do `CComVariant` objeto.|
|[CComVariant::ReadFromStream](#readfromstream)|Carrega uma VARIANTE de um fluxo.|
|[CComVariant::SetByRef](#setbyref)|Inicializa o `CComVariant` objeto e define o `vt` membro para VT_BYREF.|
|[CComVariant::WriteToStream](#writetostream)|Salva a VARIANTE subjacente em um fluxo.|

### <a name="public-operators"></a>Operadores públicos

|||
|-|-|
|[CComVariant::operator <](#operator_lt)|Indica se o `CComVariant` objeto é menor que a VARIANTE especificada.|
|[CComVariant::operator >](#operator_gt)|Indica se o `CComVariant` objeto é maior que a VARIANTE especificada.|
|[operador! =](#operator_neq)|Indica se o `CComVariant` objeto não é igual a VARIANTE especificada.|
|[operador =](#operator_eq)|Atribui um valor para o `CComVariant` objeto.|
|[operador = =](#operator_eq_eq)|Indica se o `CComVariant` objeto é igual a VARIANTE especificada.|

## <a name="remarks"></a>Comentários

`CComVariant` encapsula o tipo VARIANT e VARIANTARG, que consiste em uma união e um membro que indica o tipo dos dados armazenados na União. Variantes são normalmente usadas na automação.

`CComVariant` deriva do tipo de VARIANTE para que possa ser usado sempre que uma VARIANTE pode ser usada. Você pode, por exemplo, use a macro V_VT para extrair o tipo de um `CComVariant` ou você pode acessar o `vt` diretamente exatamente como você pode fazer com uma VARIANTE do membro.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagVARIANT`

`CComVariant`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

##  <a name="attach"></a>  CComVariant::Attach

Limpa com segurança o conteúdo atual do `CComVariant` do objeto, copia o conteúdo de *pSrc* para esse objeto, em seguida, define o tipo de variante de *pSrc* como VT_EMPTY.

```
HRESULT Attach(VARIANT* pSrc);
```

### <a name="parameters"></a>Parâmetros

*pSrc*<br/>
[in] Aponta para o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) a ser anexado ao objeto.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Propriedade dos dados mantidos pela *pSrc* é transferido para o `CComVariant` objeto.

##  <a name="ccomvariant"></a>  CComVariant::CComVariant

Cada construtor manipula a inicialização segura do `CComVariant` objeto chamando o `VariantInit` função do Win32 ou definindo o valor do objeto e o tipo de acordo com os parâmetros passados.

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

*varSrc*<br/>
[in] O `CComVariant` ou VARIANTE usado para inicializar o `CComVariant` objeto. O conteúdo da variante de fonte é copiado para o destino sem conversão.

*lpszSrc*<br/>
[in] A cadeia de caracteres usada para inicializar o `CComVariant` objeto. Você pode passar uma cadeia de caracteres terminada em zero larga (Unicode) para a versão LPCOLESTR do construtor ou uma cadeia de caracteres ANSI para a versão LPCSTR. Em ambos os casos a cadeia de caracteres é convertida para um BSTR alocado usando Unicode `SysAllocString`. O tipo do `CComVariant` objeto será VT_BSTR.

*bSrc*<br/>
[in] O **bool** usado para inicializar o `CComVariant` objeto. O **bool** argumento é convertido para um VARIANT_BOOL antes de serem armazenados. O tipo do `CComVariant` objeto será VT_BOOL.

*nSrc*<br/>
[in] O **int**, **bytes**, **curto**, **longo**, LONGLONG, ULONGLONG, **unsigned short**, **unsigned long**, ou **int sem sinal** usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_I4, VT_UI1, VT_I2, VT_I4, VT_I8, VT_UI8, VT_UI4, VT_UI2 ou VT_UI4, respectivamente.

*vtSrc*<br/>
[in] O tipo da variante. Quando o primeiro parâmetro é **int**, os tipos válidos são VT_I4 e VT_INT. Quando o primeiro parâmetro é **longo**, os tipos válidos são VT_I4 e VT_ERROR. Quando o primeiro parâmetro é **duplas**, os tipos válidos são VT_R8 e VT_DATE. Quando o primeiro parâmetro é **unsigned int**, os tipos válidos são VT_UI4 e VT_UINT.

*{1&gt;fltsrc*<br/>
[in] O **float** usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_R4.

*dblsrc&lt;1}*<br/>
[in] O **duplas** usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_R8.

*1&gt;Operator=(&lt;1}{2&gt;cysrc&lt;2}{3&gt;)&lt;3*<br/>
[in] O `CY` usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_CY.

*pSrc*<br/>
[in] O `IDispatch` ou `IUnknown` ponteiro usado para inicializar o `CComVariant` objeto. `AddRef` será chamado no ponteiro de interface. O tipo do `CComVariant` objeto será VT_DISPATCH ou VT_UNKNOWN, respectivamente.

Ou, o ponteiro SAFERRAY usado para inicializar o `CComVariant` objeto. Uma cópia de um SAFEARRAY de é armazenada no `CComVariant` objeto. O tipo do `CComVariant` objeto será uma combinação do tipo original do SAFEARRAY e VT_ARRAY.

*cSrc*<br/>
[in] O **char** usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_I1.

*1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3*<br/>
[in] O BSTR é usado para inicializar o `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_BSTR.

### <a name="remarks"></a>Comentários

O destruidor gerencia a limpeza chamando [CComVariant::Clear](#clear).

##  <a name="dtor"></a>  CComVariant:: ~ CComVariant

O destruidor.

```
~CComVariant() throw();
```

### <a name="remarks"></a>Comentários

Este método gerencia a limpeza chamando [CComVariant::Clear](#clear).

##  <a name="changetype"></a>  CComVariant::ChangeType

Converte o `CComVariant` objeto para um novo tipo.

```
HRESULT ChangeType(VARTYPE vtNew, const VARIANT* pSrc = NULL);
```

### <a name="parameters"></a>Parâmetros

*vtNew*<br/>
[in] O novo tipo para o `CComVariant` objeto.

*pSrc*<br/>
[in] Um ponteiro para a VARIANTE cujo valor será convertido para o novo tipo. O valor padrão é NULL, o que significa o `CComVariant` objeto será convertido em vigor.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se você passar um valor *pSrc*, `ChangeType` usará essa VARIANTE como a origem para a conversão. Caso contrário, o `CComVariant` objeto será a origem.

##  <a name="clear"></a>  CComVariant::Clear

Limpa a `CComVariant` objeto chamando o `VariantClear` função do Win32.

```
HRESULT Clear();
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O destrutor automaticamente chama `Clear`.

##  <a name="copy"></a>  CComVariant::Copy

Libera o `CComVariant` do objeto e, em seguida, atribui a ela uma cópia da VARIANTE especificada.

```
HRESULT Copy(const VARIANT* pSrc);
```

### <a name="parameters"></a>Parâmetros

*pSrc*<br/>
[in] Um ponteiro para o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) a serem copiados.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="copyto"></a>  CComVariant::CopyTo

Copia o conteúdo do `CComVariant` objeto.

```
HRESULT CopyTo(BSTR* pstrDest);
```

### <a name="parameters"></a>Parâmetros

*pstrDest*<br/>
Aponta para um BSTR que receberá uma cópia do conteúdo do `CComVariant` objeto.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O `CComVariant` objeto deve ser do tipo VT_BSTR.

##  <a name="detach"></a>  CComVariant::Detach

Desanexa a VARIANTE subjacente do `CComVariant` do objeto e define o tipo do objeto como VT_EMPTY.

```
HRESULT Detach(VARIANT* pDest);
```

### <a name="parameters"></a>Parâmetros

*pDest*<br/>
[out] Retorna o valor de VARIANTE subjacente do objeto.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Observe que o conteúdo da VARIANTE é referenciado por *pDest* será limpo automaticamente antes de ser atribuído o valor e o tipo de chamada `CComVariant` objeto.

##  <a name="getsize"></a>  CComVariant::GetSize

Para variantes de tamanho fixo de simples, esse método retorna o **sizeof** tipo de dados subjacente adição **sizeof(VARTYPE)**.

```
ULONG GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho em bytes do conteúdo atual do `CComVariant` objeto.

### <a name="remarks"></a>Comentários

Se a VARIANTE contém um ponteiro de interface `GetSize` pede `IPersistStream` ou `IPersistStreamInit`. Se for bem-sucedido, o valor retornado é de 32 bits de ordem baixa do valor retornado por `GetSizeMax` mais o **sizeof** um CLSID e **sizeof(VARTYPE)**. Se o ponteiro de interface for NULL, `GetSize` retorna o **sizeof** um CLSID adição **sizeof(VARTYPE)**. Se o tamanho total é maior do que ULONG_MAX, `GetSize` retorna **sizeof(VARTYPE)** que indica um erro.

Em todos os outros casos, uma VARIANTE temporária do tipo VT_BSTR é forçada da VARIANTE atual. O comprimento desse BSTR é calculado como o tamanho do comprimento da cadeia de caracteres mais o comprimento da cadeia de caracteres em si mais o tamanho do caractere nulo adição **sizeof(VARTYPE)**. Se a VARIANTE não pode ser forçada para uma VARIANTE do tipo VT_BSTR, `GetSize` retorna **sizeof(VARTYPE)**.

O tamanho retornado por esse método corresponde ao número de bytes usado por [CComVariant::WriteToStream](#writetostream) sob condições bem-sucedida.

##  <a name="operator_eq"></a>  CComVariant::operator =

Atribui um valor e o tipo correspondente para o `CComVariant` objeto.

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

*varSrc*<br/>
[in] O `CComVariant` ou [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) a ser atribuído ao `CComVariant` objeto. O conteúdo da variante de fonte é copiado para o destino sem conversão.

*1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3*<br/>
[in] O BSTR a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_BSTR.

*lpszSrc*<br/>
[in] A cadeia de caracteres a ser atribuída ao `CComVariant` objeto. Você pode passar uma cadeia de caracteres terminada em zero larga (Unicode) para a versão LPCOLESTR do operador ou uma cadeia de caracteres ANSI para a versão LPCSTR. Em ambos os casos, a cadeia de caracteres é convertida para um BSTR alocado usando Unicode `SysAllocString`. O tipo do `CComVariant` objeto será VT_BSTR.

*bSrc*<br/>
[in] O **bool** a ser atribuído ao `CComVariant` objeto. O **bool** argumento é convertido para um VARIANT_BOOL antes de serem armazenados. O tipo do `CComVariant` objeto será VT_BOOL.

*nSrc*<br/>
[in] O **int**, BYTE, **curto**, **longo**, LONGLONG, ULONGLONG, **unsigned short**, **unsigned long**, ou **int sem sinal** a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_I4, VT_UI1, VT_I2, VT_I4, VT_I8, VT_UI8, VT_UI4, VT_UI2 ou VT_UI4, respectivamente.

*{1&gt;fltsrc*<br/>
[in] O **float** a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_R4.

*dblsrc&lt;1}*<br/>
[in] O **duplas** a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_R8.

*1&gt;Operator=(&lt;1}{2&gt;cysrc&lt;2}{3&gt;)&lt;3*<br/>
[in] O `CY` a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_CY.

*pSrc*<br/>
[in] O `IDispatch` ou `IUnknown` ponteiro a ser atribuído ao `CComVariant` objeto. `AddRef` será chamado no ponteiro de interface. O tipo do `CComVariant` objeto será VT_DISPATCH ou VT_UNKNOWN, respectivamente.

Ou, um ponteiro SAFEARRAY a ser atribuído ao `CComVariant` objeto. Uma cópia de um SAFEARRAY de é armazenada no `CComVariant` objeto. O tipo do `CComVariant` objeto será uma combinação do tipo original do SAFEARRAY e VT_ARRAY.

*cSrc*<br/>
[in] O caractere a ser atribuído ao `CComVariant` objeto. O tipo do `CComVariant` objeto será VT_I1.

##  <a name="operator_eq_eq"></a>  CComVariant::operator = =

Indica se o `CComVariant` objeto é igual a VARIANTE especificada.

```
bool operator==(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retorna VERDADEIRO se o valor e o tipo de *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3* são iguais ao valor e tipo, respectivamente, da `CComVariant` objeto. Caso contrário, FALSE. O operador usa a localidade do usuário padrão para executar a comparação.

O operador compara apenas o valor dos tipos variantes. Ele compara cadeias de caracteres, inteiros e pontos flutuantes, mas não matrizes ou registros.

##  <a name="operator_neq"></a>  CComVariant::operator! =

Indica se o `CComVariant` objeto não é igual a VARIANTE especificada.

```
bool operator!=(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retorna VERDADEIRO se o valor ou o tipo de *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3* não é igual ao valor ou tipo, respectivamente, da `CComVariant` objeto. Caso contrário, FALSE. O operador usa a localidade do usuário padrão para executar a comparação.

O operador compara apenas o valor dos tipos variantes. Ele compara cadeias de caracteres, inteiros e pontos flutuantes, mas não matrizes ou registros.

##  <a name="operator_lt"></a>  CComVariant::operator &lt;

Indica se o `CComVariant` objeto é menor que a VARIANTE especificada.

```
bool operator<(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retornará TRUE se o valor de `CComVariant` objeto é menor que o valor da *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3*. Caso contrário, FALSE. O operador usa a localidade do usuário padrão para executar a comparação.

##  <a name="operator_gt"></a>  CComVariant::operator &gt;

Indica se o `CComVariant` objeto é maior que a VARIANTE especificada.

```
bool operator>(const VARIANT& varSrc) const throw();
```

### <a name="remarks"></a>Comentários

Retorna VERDADEIRO se o valor da `CComVariant` objeto é maior que o valor da *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3*. Caso contrário, FALSE. O operador usa a localidade do usuário padrão para executar a comparação.

##  <a name="readfromstream"></a>  CComVariant::ReadFromStream

Define a VARIANTE subjacente para a VARIANTE contida em um fluxo especificado.

```
HRESULT ReadFromStream(IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
[in] Um ponteiro para o [IStream](/windows/desktop/api/objidl/nn-objidl-istream) interface no fluxo que contém os dados.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

`ReadToStream` requer uma chamada anterior a [WriteToStream](#writetostream).

##  <a name="setbyref"></a>  CComVariant::SetByRef

Inicializa o `CComVariant` objeto e define o `vt` membro para VT_BYREF.

```
template < typename T >
void SetByRef(T* pT) throw();
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de VARIANTE, por exemplo, BSTR, **int**, ou **char**.

*pT*<br/>
O ponteiro usado para inicializar o `CComVariant` objeto.

### <a name="remarks"></a>Comentários

`SetByRef` é um modelo de função que inicializa o `CComVariant` objeto no ponteiro *pT* e define o `vt` membro para VT_BYREF. Por exemplo:

[!code-cpp[NVC_ATL_Utilities#76](../../atl/codesnippet/cpp/ccomvariant-class_1.cpp)]

##  <a name="writetostream"></a>  CComVariant::WriteToStream

Salva a VARIANTE subjacente em um fluxo.

```
HRESULT WriteToStream(IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
[in] Um ponteiro para o [IStream](/windows/desktop/api/objidl/nn-objidl-istream) interface em um fluxo.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)