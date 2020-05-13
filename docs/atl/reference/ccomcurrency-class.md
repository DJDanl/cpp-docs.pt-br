---
title: Classe CcomCurrency
ms.date: 11/04/2016
f1_keywords:
- CComCurrency
- ATLCUR/ATL::CComCurrency
- ATLCUR/ATL::CComCurrency::CComCurrency
- ATLCUR/ATL::CComCurrency::GetCurrencyPtr
- ATLCUR/ATL::CComCurrency::GetFraction
- ATLCUR/ATL::CComCurrency::GetInteger
- ATLCUR/ATL::CComCurrency::Round
- ATLCUR/ATL::CComCurrency::SetFraction
- ATLCUR/ATL::CComCurrency::SetInteger
- ATLCUR/ATL::CComCurrency::m_currency
helpviewer_keywords:
- CComCurrency class
ms.assetid: a1c3d10a-bba6-40cc-8bcf-aed9023c8a9e
ms.openlocfilehash: 541944e03e9caf6cba15612cf9e7cbbd239555ca
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327937"
---
# <a name="ccomcurrency-class"></a>Classe CcomCurrency

`CComCurrency`tem métodos e operadores para criar e gerenciar um objeto CURRENCY.

## <a name="syntax"></a>Sintaxe

```
class CComCurrency
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCurrency::CComCurrency](#ccomcurrency)|O construtor de `CComCurrency` um objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCurrency::GetCurrencyPtr](#getcurrencyptr)|Retorna o endereço `m_currency` de um membro de dados.|
|[CComCurrency::GetFraction](#getfraction)|Chame este método para retornar o `CComCurrency` componente fracionado de um objeto.|
|[CComCurrency::GetInteger](#getinteger)|Chame este método para retornar o `CComCurrency` componente inteiro de um objeto.|
|[CComCurrency::Round](#round)|Chame este método `CComCurrency` para arredondar um objeto para o valor inteiro mais próximo.|
|[CComCurrency::SetFraction](#setfraction)|Chame este método para definir o `CComCurrency` componente fracionado de um objeto.|
|[CComCurrency::SetInteger](#setinteger)|Chame este método para definir o `CComCurrency` componente inteiro de um objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCurrency::operador -](#operator_-)|Este operador é usado para `CComCurrency` executar subtração em um objeto.|
|[CComCurrency::operador !=](#operator_neq)|Compara dois objetos `CComCurrency` quanto à desigualdade.|
|[CComCurrency::operador *](#operator_star)|Este operador é usado para `CComCurrency` realizar a multiplicação em um objeto.|
|[CComCurrency::operador *=](#operator_star_eq)|Este operador é usado para `CComCurrency` executar a multiplicação em um objeto e atribuir-o o resultado.|
|[CComCurrency::operador /](#operator_div)|Este operador é usado para `CComCurrency` executar divisão em um objeto.|
|[CComCurrency::operador /=](#operator_div_eq)|Este operador é usado para `CComCurrency` executar a divisão em um objeto e atribuir-o o resultado.|
|[CComCurrency::operador +](#operator_add)|Este operador é usado para `CComCurrency` executar a adição em um objeto.|
|[CComCurrency::operador +=](#operator_add_eq)|Este operador é usado para `CComCurrency` executar a adição em um objeto e atribuir o resultado ao objeto atual.|
|[CComCurrency::<do operador](#operator_lt)|Este operador compara dois `CComCurrency` objetos para determinar o menor.|
|[CComCurrency::<do operador =](#operator_lt_eq)|Este operador compara dois `CComCurrency` objetos para determinar a igualdade ou o menor.|
|[CComCurrency::operador =](#operator_eq)|Este operador atribui `CComCurrency` o objeto a um novo valor.|
|[CComCurrency::operador -=](#operator_-_eq)|Este operador é usado para `CComCurrency` executar subtração em um objeto e atribuir-o o resultado.|
|[CComCurrency::operador ==](#operator_eq_eq)|Este operador compara dois `CComCurrency` objetos para a igualdade.|
|[CComCurrency::>do operador](#operator_gt)|Este operador compara dois `CComCurrency` objetos para determinar o maior.|
|[CComCurrency::>do operador =](#operator_gt_eq)|Este operador compara dois `CComCurrency` objetos para determinar a igualdade ou o maior.|
|[CComCurrency::operator CURRENCY](#operator_currency)|Lança um objeto CURRENCY.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCurrency::m_currency](#m_currency)|A variável CURRENCY criada pela sua instância de classe.|

## <a name="remarks"></a>Comentários

`CComCurrency`é um invólucro para o tipo de dados CURRENCY. Currency é implementado como um valor inteiro de complemento de 8 bytes dois escalado por 10.000. Isso dá um número de ponto fixo com 15 dígitos à esquerda do ponto decimal e 4 dígitos para a direita. O tipo de dados CURRENCY é extremamente útil para cálculos envolvendo dinheiro, ou para quaisquer cálculos de ponto fixo onde a precisão é importante.

O `CComCurrency` invólucro implementa operações aritméticas, de atribuição e de comparação para este tipo de ponto fixo. Os aplicativos suportados foram selecionados para controlar os erros de arredondamento que podem ocorrer durante os cálculos de ponto fixo.

O `CComCurrency` objeto fornece acesso aos números em ambos os lados do ponto decimal na forma de dois componentes: um componente inteiro que armazena o valor à esquerda do ponto decimal e um componente fracionado que armazena o valor à direita do ponto decimal. O componente fracionado é armazenado internamente como um valor inteiro entre -9999 (CY_MIN_FRACTION) e +9999 (CY_MAX_FRACTION). O método [CComCurrency::GetFraction](#getfraction) retorna um valor dimensionado por um fator de 10000 (CY_SCALE).

Ao especificar os componentes inteiros e `CComCurrency` fracionados de um objeto, lembre-se de que o componente fracionado é um número na faixa 0 a 9999. Isso é importante ao lidar com uma moeda como o dólar americano que expressa valores usando apenas dois dígitos significativos após o ponto decimal. Mesmo que os dois últimos dígitos não sejam exibidos, eles devem ser levados em conta.

|Valor|Possíveis atribuições da CComCurrency|
|-----------|---------------------------------------|
|$10.50|CComCurrency(10.5000) *ou* CComCurrency(10.50)|
|$10.05|CComCurrency(10.500) *ou* CComCurrency(10.05)|

Os valores CY_MIN_FRACTION, CY_MAX_FRACTION e CY_SCALE são definidos em atlcur.h.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcur.h

## <a name="ccomcurrencyccomcurrency"></a><a name="ccomcurrency"></a>CComCurrency::CComCurrency

O construtor.

```
CComCurrency() throw();
CComCurrency(const CComCurrency& curSrc) throw();
CComCurrency(CURRENCY cySrc) throw();
CComCurrency(DECIMAL dSrc);
CComCurrency(ULONG ulSrc);
CComCurrency(USHORT usSrc);
CComCurrency(CHAR cSrc);
CComCurrency(DOUBLE dSrc);
CComCurrency(FLOAT fSrc);
CComCurrency(LONG lSrc);
CComCurrency(SHORT sSrc);
CComCurrency(BYTE bSrc);
CComCurrency(LONGLONG nInteger, SHORT nFraction);
explicit CComCurrency(LPDISPATCH pDispSrc);
explicit CComCurrency(const VARIANT& varSrc);
explicit CComCurrency(LPCWSTR szSrc);
explicit CComCurrency(LPCSTR szSrc);
```

### <a name="parameters"></a>Parâmetros

*curSrc*<br/>
Um objeto `CComCurrency` existente.

*cisrc*<br/>
Uma variável do tipo MOEDA.

*bSrc*, *dSrc*, *fSrc*, *lSrc*, *sSrc*, *ulSrc, usSrc*<br/>
O valor inicial dado `m_currency`à variável membro .

*Csrc*<br/>
Um caractere contendo o valor inicial `m_currency`dado à variável membro .

*nInteger,* *nFraction*<br/>
Os componentes inteiros e fracionados do valor monetário inicial. Consulte a visão geral [da CComCurrency](../../atl/reference/ccomcurrency-class.md) para obter mais informações.

*pDispSrc*<br/>
Um `IDispatch` ponteiro.

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Uma variável do tipo VARIANT. A localização do segmento atual é usada para realizar a conversão.

*szSrc*<br/>
Uma seqüência Unicode ou ANSI contendo o valor inicial. A localização do segmento atual é usada para realizar a conversão.

### <a name="remarks"></a>Comentários

O construtor define o valor inicial de [CComCurrency::m_currency](#m_currency), e aceita uma ampla gama de tipos de dados, incluindo inteiros, strings, números de pontos flutuantes, variáveis DE MOEDA e outros `CComCurrency` objetos. Se nenhum valor for `m_currency` fornecido, é definido como 0.

Em caso de erro, como um estouro, os construtores sem uma especificação `AtlThrow` de exceção vazia **(throw()** chamada com um HRESULT descrevendo o erro.

Ao usar valores flutuantes ou duplos para `CComCurrency(10.50)` atribuir `CComCurrency(10,5000)` um `CComCurrency(10,50)`valor, observe que é equivalente e não .

## <a name="ccomcurrencygetcurrencyptr"></a><a name="getcurrencyptr"></a>CComCurrency::GetCurrencyPtr

Retorna o endereço `m_currency` de um membro de dados.

```
CURRENCY* GetCurrencyPtr() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o endereço `m_currency` de um membro de dados

## <a name="ccomcurrencygetfraction"></a><a name="getfraction"></a>CComCurrency::GetFraction

Chame este método para retornar o `CComCurrency` componente fracionado do objeto.

```
SHORT GetFraction() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o componente fracionado do `m_currency` membro de dados.

### <a name="remarks"></a>Comentários

O componente fracionado é um valor inteiro de 4 dígitos entre -9999 (CY_MIN_FRACTION) e +9999 (CY_MAX_FRACTION). `GetFraction`retorna este valor escalado por 10000 (CY_SCALE). Os valores de CY_MIN_FRACTION, CY_MAX_FRACTION e CY_SCALE são definidos em atlcur.h.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#50](../../atl/codesnippet/cpp/ccomcurrency-class_1.cpp)]

## <a name="ccomcurrencygetinteger"></a><a name="getinteger"></a>CComCurrency::GetInteger

Chame este método para obter o `CComCurrency` componente inteiro de um objeto.

```
LONGLONG GetInteger() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o componente inteiro `m_currency` do membro de dados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#51](../../atl/codesnippet/cpp/ccomcurrency-class_2.cpp)]

## <a name="ccomcurrencym_currency"></a><a name="m_currency"></a>CComCurrency::m_currency

O membro de dados CURRENCY.

```
CURRENCY m_currency;
```

### <a name="remarks"></a>Comentários

Este membro detém a moeda acessada e manipulada pelos métodos desta classe.

## <a name="ccomcurrencyoperator--"></a><a name="operator_-"></a>CComCurrency::operador -

Este operador é usado para `CComCurrency` executar subtração em um objeto.

```
CComCurrency operator-() const;
CComCurrency operator-(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency` .

### <a name="return-value"></a>Valor retornado

Retorna `CComCurrency` um objeto representando o resultado da subtração. Em caso de erro, como um estouro, `AtlThrow` este operador liga com um HRESULT descrevendo o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#55](../../atl/codesnippet/cpp/ccomcurrency-class_3.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_neq"></a>CComCurrency::operador !=

Este operador compara dois objetos à desigualdade.

```
bool operator!= (const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
O objeto `CComCurrency` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o item a `CComCurrency` ser comparado não for igual ao objeto; caso contrário, FALSE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#56](../../atl/codesnippet/cpp/ccomcurrency-class_4.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_star"></a>CComCurrency::operador *

Este operador é usado para `CComCurrency` realizar a multiplicação em um objeto.

```
CComCurrency operator*(long nOperand) const;
CComCurrency operator*(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*nOperand*<br/>
O multiplicador.

*cur*<br/>
O `CComCurrency` objeto usado como multiplicador.

### <a name="return-value"></a>Valor retornado

Retorna `CComCurrency` um objeto representando o resultado da multiplicação. Em caso de erro, como um estouro, `AtlThrow` este operador liga com um HRESULT descrevendo o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#57](../../atl/codesnippet/cpp/ccomcurrency-class_5.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_star_eq"></a>CComCurrency::operador\*=

Este operador é usado para `CComCurrency` executar a multiplicação em um objeto e atribuir-o o resultado.

```
const CComCurrency& operator*= (long nOperand);
const CComCurrency& operator*= (const CComCurrency& cur);
```

### <a name="parameters"></a>Parâmetros

*nOperand*<br/>
O multiplicador.

*cur*<br/>
O `CComCurrency` objeto usado como multiplicador.

### <a name="return-value"></a>Valor retornado

Retorna o `CComCurrency` objeto atualizado. Em caso de erro, como um estouro, `AtlThrow` este operador liga com um HRESULT descrevendo o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#58](../../atl/codesnippet/cpp/ccomcurrency-class_6.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_div"></a>CComCurrency::operador /

Este operador é usado para `CComCurrency` executar divisão em um objeto.

```
CComCurrency operator/(long nOperand) const;
```

### <a name="parameters"></a>Parâmetros

*nOperand*<br/>
O divisor.

### <a name="return-value"></a>Valor retornado

Retorna `CComCurrency` um objeto representando o resultado da divisão. Se o divisor for 0, uma falha de afirmação ocorrerá.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#59](../../atl/codesnippet/cpp/ccomcurrency-class_7.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_div_eq"></a>CComCurrency::operador /=

Este operador é usado para `CComCurrency` executar a divisão em um objeto e atribuir-o o resultado.

```
const CComCurrency& operator/= (long nOperand);
```

### <a name="parameters"></a>Parâmetros

*nOperand*<br/>
O divisor.

### <a name="return-value"></a>Valor retornado

Retorna o `CComCurrency` objeto atualizado. Se o divisor for 0, uma falha de afirmação ocorrerá.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#60](../../atl/codesnippet/cpp/ccomcurrency-class_8.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_add"></a>CComCurrency::operador +

Este operador é usado para `CComCurrency` executar a adição em um objeto.

```
CComCurrency operator+(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
O `CComCurrency` objeto a ser adicionado ao objeto original.

### <a name="return-value"></a>Valor retornado

Retorna `CComCurrency` um objeto representando o resultado da adição. Em caso de erro, como um estouro, `AtlThrow` este operador liga com um HRESULT descrevendo o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#61](../../atl/codesnippet/cpp/ccomcurrency-class_9.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_add_eq"></a>CComCurrency::operador +=

Este operador é usado para `CComCurrency` executar a adição em um objeto e atribuir o resultado ao objeto atual.

```
const CComCurrency& operator+= (const CComCurrency& cur);
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
O objeto `CComCurrency`.

### <a name="return-value"></a>Valor retornado

Retorna o `CComCurrency` objeto atualizado. Em caso de erro, como um estouro, `AtlThrow` este operador liga com um HRESULT descrevendo o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#62](../../atl/codesnippet/cpp/ccomcurrency-class_10.cpp)]

## <a name="ccomcurrencyoperator-lt"></a><a name="operator_lt"></a>CComCurrency::operador&lt;

Este operador compara dois `CComCurrency` objetos para determinar o menor.

```
bool operator<(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency` .

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for menor que o segundo, FALSO de outra forma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#63](../../atl/codesnippet/cpp/ccomcurrency-class_11.cpp)]

## <a name="ccomcurrencyoperator-lt"></a><a name="operator_lt_eq"></a>CComCurrency::operador&lt;=

Este operador compara dois `CComCurrency` objetos para determinar a igualdade ou o menor.

```
bool operator<= (const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency` .

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for menor ou igual ao segundo, FALSO de outra forma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#64](../../atl/codesnippet/cpp/ccomcurrency-class_12.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_eq"></a>CComCurrency::operador =

Este operador atribui `CComCurrency` o objeto a um novo valor.

```
const CComCurrency& operator= (const CComCurrency& curSrc) throw();
const CComCurrency& operator= (CURRENCY cySrc) throw();
const CComCurrency& operator= (FLOAT fSrc);
const CComCurrency& operator= (SHORT sSrc);
const CComCurrency& operator= (LONG lSrc);
const CComCurrency& operator= (BYTE bSrc);
const CComCurrency& operator= (USHORT usSrc);
const CComCurrency& operator= (DOUBLE dSrc);
const CComCurrency& operator= (CHAR cSrc);
const CComCurrency& operator= (ULONG ulSrc);
const CComCurrency& operator= (DECIMAL dSrc);
```

### <a name="parameters"></a>Parâmetros

*curSrc*<br/>
Um objeto `CComCurrency` .

*cisrc*<br/>
Uma variável do tipo MOEDA.

*sSrc,* *fSrc,* *lSrc,* *bSrc,* *usSrc,* *dSrc,* *cSrc,* *ulSrc,* *dSrc*<br/>
O valor numérico para `CComCurrency` atribuir ao objeto.

### <a name="return-value"></a>Valor retornado

Retorna o `CComCurrency` objeto atualizado. Em caso de erro, como um estouro, `AtlThrow` este operador liga com um HRESULT descrevendo o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#65](../../atl/codesnippet/cpp/ccomcurrency-class_13.cpp)]

## <a name="ccomcurrencyoperator--"></a><a name="operator_-_eq"></a>CComCurrency::operador -=

Este operador é usado para `CComCurrency` executar subtração em um objeto e atribuir-o o resultado.

```
const CComCurrency& operator-= (const CComCurrency& cur);
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency` .

### <a name="return-value"></a>Valor retornado

Retorna o `CComCurrency` objeto atualizado. Em caso de erro, como um estouro, `AtlThrow` este operador liga com um HRESULT descrevendo o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#66](../../atl/codesnippet/cpp/ccomcurrency-class_14.cpp)]

## <a name="ccomcurrencyoperator-"></a><a name="operator_eq_eq"></a>CComCurrency::operador ==

Este operador compara dois `CComCurrency` objetos para a igualdade.

```
bool operator== (const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
O objeto `CComCurrency` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se os objetos forem iguais (ou seja, os membros de `m_currency` dados, inteiros e fracionados, em ambos os objetos têm o mesmo valor), FALSO de outra forma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#67](../../atl/codesnippet/cpp/ccomcurrency-class_15.cpp)]

## <a name="ccomcurrencyoperator-gt"></a><a name="operator_gt"></a>CComCurrency::operador&gt;

Este operador compara dois `CComCurrency` objetos para determinar o maior.

```
bool operator>(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency` .

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for maior que o segundo, FALSO de outra forma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#68](../../atl/codesnippet/cpp/ccomcurrency-class_16.cpp)]

## <a name="ccomcurrencyoperator-gt"></a><a name="operator_gt_eq"></a>CComCurrency::operador&gt;=

Este operador compara dois `CComCurrency` objetos para determinar a igualdade ou o maior.

```
bool operator>= (const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency` .

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for maior ou igual ao segundo, FALSO de outra forma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#69](../../atl/codesnippet/cpp/ccomcurrency-class_17.cpp)]

## <a name="ccomcurrencyoperator-currency"></a><a name="operator_currency"></a>CComCurrency::operator CURRENCY

Esses operadores são usados para lançar um `CComCurrency` objeto a um tipo de dados CURRENCY.

```
operator CURRENCY&() throw();
operator const CURRENCY&() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma referência a um objeto CURRENCY.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#70](../../atl/codesnippet/cpp/ccomcurrency-class_18.cpp)]

## <a name="ccomcurrencyround"></a><a name="round"></a>CComCurrency::Round

Chame este método para arredondar a moeda para um número especificado de casas decimais.

```
HRESULT Roundint nDecimals);
```

### <a name="parameters"></a>Parâmetros

*nDecimais*<br/>
O número de dígitos aos quais `m_currency` será arredondado, na faixa de 0 a 4.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#52](../../atl/codesnippet/cpp/ccomcurrency-class_19.cpp)]

## <a name="ccomcurrencysetfraction"></a><a name="setfraction"></a>CComCurrency::SetFraction

Chame este método para definir o `CComCurrency` componente fracionado de um objeto.

```
HRESULT SetFraction(SHORT nFraction);
```

### <a name="parameters"></a>Parâmetros

*nFraction*<br/>
O valor a ser atribuído ao componente `m_currency` fracionado do membro de dados. O sinal do componente fracionado deve ser o mesmo do componente inteiro, e o valor deve estar na faixa -9999 (CY_MIN_FRACTION) a +9999 (CY_MAX_FRACTION).

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#53](../../atl/codesnippet/cpp/ccomcurrency-class_20.cpp)]

## <a name="ccomcurrencysetinteger"></a><a name="setinteger"></a>CComCurrency::SetInteger

Chame este método para definir o `CComCurrency` componente inteiro de um objeto.

```
HRESULT SetInteger(LONGLONG nInteger);
```

### <a name="parameters"></a>Parâmetros

*nInteger*<br/>
O valor a ser atribuído ao componente `m_currency` inteiro do membro de dados. O sinal do componente inteiro deve corresponder ao sinal do componente fracionado existente.

*nInteger* deve estar no intervalo CY_MIN_INTEGER para CY_MAX_INTEGER inclusive. Esses valores são definidos em atlcur.h.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#54](../../atl/codesnippet/cpp/ccomcurrency-class_21.cpp)]

## <a name="see-also"></a>Confira também

[Classe COleCurrency](../../mfc/reference/colecurrency-class.md)<br/>
[Moeda](/windows/win32/api/wtypes/ns-wtypes-cy~r1)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
