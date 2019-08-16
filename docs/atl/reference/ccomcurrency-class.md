---
title: Classe CComCurrency
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
ms.openlocfilehash: 11463b7113876abdf0743b9f8c7df373fadd99ef
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497287"
---
# <a name="ccomcurrency-class"></a>Classe CComCurrency

`CComCurrency`tem métodos e operadores para criar e gerenciar um objeto de moeda.

## <a name="syntax"></a>Sintaxe

```
class CComCurrency
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCurrency::CComCurrency](#ccomcurrency)|O construtor de um `CComCurrency` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCurrency::GetCurrencyPtr](#getcurrencyptr)|Retorna o endereço de um `m_currency` membro de dados.|
|[CComCurrency::GetFraction](#getfraction)|Chame esse método para retornar o componente fracionário de um `CComCurrency` objeto.|
|[CComCurrency::GetInteger](#getinteger)|Chame esse método para retornar o componente de inteiro de `CComCurrency` um objeto.|
|[CComCurrency::Round](#round)|Chame esse método para arredondar um `CComCurrency` objeto para o valor inteiro mais próximo.|
|[CComCurrency::SetFraction](#setfraction)|Chame esse método para definir o componente fracionário de um `CComCurrency` objeto.|
|[CComCurrency::SetInteger](#setinteger)|Chame esse método para definir o componente de inteiro de `CComCurrency` um objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CComCurrency:: Operator](#operator_-)|Esse operador é usado para executar a subtração em `CComCurrency` um objeto.|
|[CComCurrency:: Operator! =](#operator_neq)|Compara dois objetos `CComCurrency` quanto à desigualdade.|
|[CComCurrency:: Operator *](#operator_star)|Esse operador é usado para executar a multiplicação em `CComCurrency` um objeto.|
|[CComCurrency:: Operator * =](#operator_star_eq)|Esse operador é usado para executar a multiplicação em `CComCurrency` um objeto e atribuir o resultado.|
|[CComCurrency:: Operator/](#operator_div)|Esse operador é usado para executar a divisão em `CComCurrency` um objeto.|
|[CComCurrency:: Operator/=](#operator_div_eq)|Esse operador é usado para executar a divisão em `CComCurrency` um objeto e atribuí-lo ao resultado.|
|[CComCurrency:: Operator +](#operator_add)|Esse operador é usado para executar adição em um `CComCurrency` objeto.|
|[CComCurrency:: Operator + =](#operator_add_eq)|Esse operador é usado para executar adição em um `CComCurrency` objeto e atribuir o resultado ao objeto atual.|
|[Operador CComCurrency:: Operator <](#operator_lt)|Esse operador compara dois `CComCurrency` objetos para determinar o menor.|
|[CComCurrency:: Operator < =](#operator_lt_eq)|Esse operador compara dois `CComCurrency` objetos para determinar a igualdade ou o menor.|
|[CComCurrency:: Operator =](#operator_eq)|Esse operador atribui o `CComCurrency` objeto a um novo valor.|
|[CComCurrency:: Operator-=](#operator_-_eq)|Esse operador é usado para executar a subtração em `CComCurrency` um objeto e atribuí-lo ao resultado.|
|[CComCurrency:: Operator = =](#operator_eq_eq)|Esse operador compara dois `CComCurrency` objetos para igualdade.|
|[Operador CComCurrency:: operator >](#operator_gt)|Esse operador compara dois `CComCurrency` objetos para determinar o maior.|
|[CComCurrency:: operator > =](#operator_gt_eq)|Esse operador compara dois `CComCurrency` objetos para determinar a igualdade ou maior.|
|[MOEDA do operador CComCurrency:: Operator](#operator_currency)|Converte um objeto CURRENCY.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCurrency::m_currency](#m_currency)|A variável de moeda criada por sua instância de classe.|

## <a name="remarks"></a>Comentários

`CComCurrency`é um wrapper para o tipo de dados CURRENCY. A moeda é implementada como um valor inteiro de complemento de 8 bytes de dois bits dimensionado por 10.000. Isso fornece um número de ponto fixo com 15 dígitos à esquerda do ponto decimal e 4 dígitos à direita. O tipo de dados CURRENCY é extremamente útil para cálculos que envolvem dinheiro ou para qualquer cálculo de ponto fixo onde a precisão é importante.

O `CComCurrency` wrapper implementa operações aritméticas, de atribuição e de comparação para esse tipo de ponto fixo. Os aplicativos com suporte foram selecionados para controlar os erros de arredondamento que podem ocorrer durante cálculos de ponto fixo.

O `CComCurrency` objeto fornece acesso aos números em ambos os lados do ponto decimal na forma de dois componentes: um componente inteiro que armazena o valor à esquerda do ponto decimal e um componente fracionário que armazena o valor à direita do. ponto decimal. O componente fracionário é armazenado internamente como um valor inteiro entre-9999 (CY_MIN_FRACTION) e + 9999 (CY_MAX_FRACTION). O método [CComCurrency:: getfracionário](#getfraction) retorna um valor dimensionado por um fator de 10000 (CY_SCALE).

Ao especificar o número inteiro e os componentes fracionários `CComCurrency` de um objeto, lembre-se de que o componente fracionário é um número no intervalo de 0 a 9999. Isso é importante ao lidar com uma moeda, como o dólar dos EUA, que expressa valores usando apenas dois dígitos significativos após o ponto decimal. Embora os dois últimos dígitos não sejam exibidos, eles devem ser levados em conta.

|Valor|Possíveis atribuições de CComCurrency|
|-----------|---------------------------------------|
|$10.50|CComCurrency (10, 5000) *ou* CComCurrency (10.50)|
|$10.05|CComCurrency (10500) *ou* CComCurrency (10.05)|

Os valores CY_MIN_FRACTION, CY_MAX_FRACTION e CY_SCALE são definidos em atlcur. h.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcur. h

##  <a name="ccomcurrency"></a>CComCurrency::CComCurrency

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

*cySrc*<br/>
Uma variável do tipo CURRENCY.

*bSrc*, *dSrc*, *fSrc*, *lSrc*, *sSrc*, *ulSrc, usSrc*<br/>
O valor inicial fornecido para a variável `m_currency`de membro.

*cSrc*<br/>
Um caractere que contém o valor inicial fornecido para a variável `m_currency`de membro.

*nInteger*, *nFraction*<br/>
Os componentes de número inteiro e fracionário do valor monetário inicial. Consulte a visão geral do [CComCurrency](../../atl/reference/ccomcurrency-class.md) para obter mais informações.

*pDispSrc*<br/>
Um `IDispatch` ponteiro.

*varSrc*<br/>
Uma variável do tipo VARIANT. A localidade do thread atual é usada para executar a conversão.

*szSrc*<br/>
Uma cadeia de caracteres Unicode ou ANSI que contém o valor inicial. A localidade do thread atual é usada para executar a conversão.

### <a name="remarks"></a>Comentários

O construtor define o valor inicial de [CComCurrency:: m_currency](#m_currency)e aceita uma ampla gama de tipos de dados, incluindo inteiros, cadeias de caracteres, números de ponto flutuante, variáveis de moeda `CComCurrency` e outros objetos. Se nenhum valor for fornecido, `m_currency` será definido como 0.

No caso de um erro, como um estouro, os construtores que não continham uma chamada `AtlThrow` **throw ()** ) com um HRESULT que descreva o erro.

Ao usar o ponto flutuante ou valores duplos para atribuir um valor, observe `CComCurrency(10.50)` que é equivalente `CComCurrency(10,5000)` a e `CComCurrency(10,50)`não.

##  <a name="getcurrencyptr"></a>CComCurrency::GetCurrencyPtr

Retorna o endereço de um `m_currency` membro de dados.

```
CURRENCY* GetCurrencyPtr() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o endereço de um `m_currency` membro de dados

##  <a name="getfraction"></a>  CComCurrency::GetFraction

Chame esse método para retornar o componente fracionário do `CComCurrency` objeto.

```
SHORT GetFraction() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o componente fracionário do membro de `m_currency` dados.

### <a name="remarks"></a>Comentários

O componente fracionário é um valor inteiro de 4 dígitos entre-9999 (CY_MIN_FRACTION) e + 9999 (CY_MAX_FRACTION). `GetFraction`retorna esse valor dimensionado por 10000 (CY_SCALE). Os valores de CY_MIN_FRACTION, CY_MAX_FRACTION e CY_SCALE são definidos em atlcur. h.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#50](../../atl/codesnippet/cpp/ccomcurrency-class_1.cpp)]

##  <a name="getinteger"></a>  CComCurrency::GetInteger

Chame esse método para obter o componente de inteiro de `CComCurrency` um objeto.

```
LONGLONG GetInteger() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o componente de inteiro do `m_currency` membro de dados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#51](../../atl/codesnippet/cpp/ccomcurrency-class_2.cpp)]

##  <a name="m_currency"></a>CComCurrency::m_currency

O membro de dados de moeda.

```
CURRENCY m_currency;
```

### <a name="remarks"></a>Comentários

Esse membro contém a moeda acessada e manipulada pelos métodos dessa classe.

##  <a name="operator_-"></a>Operador CComCurrency:: Operator

Esse operador é usado para executar a subtração em `CComCurrency` um objeto.

```
CComCurrency operator-() const;
CComCurrency operator-(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency`.

### <a name="return-value"></a>Valor de retorno

Retorna um `CComCurrency` objeto que representa o resultado da subtração. No caso de um erro, como um estouro, esse operador chama `AtlThrow` um HRESULT que descreve o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#55](../../atl/codesnippet/cpp/ccomcurrency-class_3.cpp)]

##  <a name="operator_neq"></a>CComCurrency:: Operator! =

Esse operador compara dois objetos para desigualdade.

```
bool operator!= (const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
O objeto `CComCurrency` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará true se o item que está sendo comparado não for igual `CComCurrency` ao objeto; caso contrário, false.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#56](../../atl/codesnippet/cpp/ccomcurrency-class_4.cpp)]

##  <a name="operator_star"></a>CComCurrency:: Operator *

Esse operador é usado para executar a multiplicação em `CComCurrency` um objeto.

```
CComCurrency operator*(long nOperand) const;
CComCurrency operator*(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*nOperand*<br/>
O multiplicador.

*cur*<br/>
O `CComCurrency` objeto usado como multiplicador.

### <a name="return-value"></a>Valor de retorno

Retorna um `CComCurrency` objeto que representa o resultado da multiplicação. No caso de um erro, como um estouro, esse operador chama `AtlThrow` um HRESULT que descreve o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#57](../../atl/codesnippet/cpp/ccomcurrency-class_5.cpp)]

##  <a name="operator_star_eq"></a>Operador CComCurrency::\*=

Esse operador é usado para executar a multiplicação em `CComCurrency` um objeto e atribuir o resultado.

```
const CComCurrency& operator*= (long nOperand);
const CComCurrency& operator*= (const CComCurrency& cur);
```

### <a name="parameters"></a>Parâmetros

*nOperand*<br/>
O multiplicador.

*cur*<br/>
O `CComCurrency` objeto usado como multiplicador.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CComCurrency` atualizado. No caso de um erro, como um estouro, esse operador chama `AtlThrow` um HRESULT que descreve o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#58](../../atl/codesnippet/cpp/ccomcurrency-class_6.cpp)]

##  <a name="operator_div"></a>CComCurrency:: Operator/

Esse operador é usado para executar a divisão em `CComCurrency` um objeto.

```
CComCurrency operator/(long nOperand) const;
```

### <a name="parameters"></a>Parâmetros

*nOperand*<br/>
O divisor.

### <a name="return-value"></a>Valor de retorno

Retorna um `CComCurrency` objeto que representa o resultado da divisão. Se o divisor for 0, ocorrerá uma falha de asserção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#59](../../atl/codesnippet/cpp/ccomcurrency-class_7.cpp)]

##  <a name="operator_div_eq"></a>  CComCurrency::operator /=

Esse operador é usado para executar a divisão em `CComCurrency` um objeto e atribuí-lo ao resultado.

```
const CComCurrency& operator/= (long nOperand);
```

### <a name="parameters"></a>Parâmetros

*nOperand*<br/>
O divisor.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CComCurrency` atualizado. Se o divisor for 0, ocorrerá uma falha de asserção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#60](../../atl/codesnippet/cpp/ccomcurrency-class_8.cpp)]

##  <a name="operator_add"></a>CComCurrency:: Operator +

Esse operador é usado para executar adição em um `CComCurrency` objeto.

```
CComCurrency operator+(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
O `CComCurrency` objeto a ser adicionado ao objeto original.

### <a name="return-value"></a>Valor de retorno

Retorna um `CComCurrency` objeto que representa o resultado da adição. No caso de um erro, como um estouro, esse operador chama `AtlThrow` um HRESULT que descreve o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#61](../../atl/codesnippet/cpp/ccomcurrency-class_9.cpp)]

##  <a name="operator_add_eq"></a>CComCurrency:: Operator + =

Esse operador é usado para executar adição em um `CComCurrency` objeto e atribuir o resultado ao objeto atual.

```
const CComCurrency& operator+= (const CComCurrency& cur);
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
O objeto `CComCurrency`.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CComCurrency` atualizado. No caso de um erro, como um estouro, esse operador chama `AtlThrow` um HRESULT que descreve o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#62](../../atl/codesnippet/cpp/ccomcurrency-class_10.cpp)]

##  <a name="operator_lt"></a>Operador CComCurrency::&lt;

Esse operador compara dois `CComCurrency` objetos para determinar o menor.

```
bool operator<(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency`.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o primeiro objeto for menor que o segundo; caso contrário, FALSE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#63](../../atl/codesnippet/cpp/ccomcurrency-class_11.cpp)]

##  <a name="operator_lt_eq"></a>Operador CComCurrency::&lt;=

Esse operador compara dois `CComCurrency` objetos para determinar a igualdade ou o menor.

```
bool operator<= (const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency`.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o primeiro objeto for menor ou igual ao segundo; caso contrário, FALSE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#64](../../atl/codesnippet/cpp/ccomcurrency-class_12.cpp)]

##  <a name="operator_eq"></a>CComCurrency:: Operator =

Esse operador atribui o `CComCurrency` objeto a um novo valor.

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
Um objeto `CComCurrency`.

*cySrc*<br/>
Uma variável do tipo CURRENCY.

*sSrc*, *fSrc*, *lSrc*, *bSrc*, *usSrc*, *dSrc*, *cSrc*, *ulSrc*, *dSrc*<br/>
O valor numérico a ser atribuído ao `CComCurrency` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CComCurrency` atualizado. No caso de um erro, como um estouro, esse operador chama `AtlThrow` um HRESULT que descreve o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#65](../../atl/codesnippet/cpp/ccomcurrency-class_13.cpp)]

##  <a name="operator_-_eq"></a>CComCurrency:: Operator-=

Esse operador é usado para executar a subtração em `CComCurrency` um objeto e atribuí-lo ao resultado.

```
const CComCurrency& operator-= (const CComCurrency& cur);
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency`.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CComCurrency` atualizado. No caso de um erro, como um estouro, esse operador chama `AtlThrow` um HRESULT que descreve o erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#66](../../atl/codesnippet/cpp/ccomcurrency-class_14.cpp)]

##  <a name="operator_eq_eq"></a>CComCurrency:: Operator = =

Esse operador compara dois `CComCurrency` objetos para igualdade.

```
bool operator== (const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
O objeto `CComCurrency` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará true se os objetos forem iguais (ou seja, os `m_currency` membros de dados, inteiro e fracionário, em ambos os objetos tiverem o mesmo valor); caso contrário, false.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#67](../../atl/codesnippet/cpp/ccomcurrency-class_15.cpp)]

##  <a name="operator_gt"></a>Operador CComCurrency::&gt;

Esse operador compara dois `CComCurrency` objetos para determinar o maior.

```
bool operator>(const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency`.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o primeiro objeto for maior que o segundo; caso contrário, FALSE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#68](../../atl/codesnippet/cpp/ccomcurrency-class_16.cpp)]

##  <a name="operator_gt_eq"></a>Operador CComCurrency::&gt;=

Esse operador compara dois `CComCurrency` objetos para determinar a igualdade ou maior.

```
bool operator>= (const CComCurrency& cur) const;
```

### <a name="parameters"></a>Parâmetros

*cur*<br/>
Um objeto `CComCurrency`.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o primeiro objeto for maior ou igual ao segundo; caso contrário, FALSE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#69](../../atl/codesnippet/cpp/ccomcurrency-class_17.cpp)]

##  <a name="operator_currency"></a>MOEDA do operador CComCurrency:: Operator

Esses operadores são usados para converter um `CComCurrency` objeto em um tipo de dados de moeda.

```
operator CURRENCY&() throw();
operator const CURRENCY&() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma referência a um objeto CURRENCY.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#70](../../atl/codesnippet/cpp/ccomcurrency-class_18.cpp)]

##  <a name="round"></a>CComCurrency:: round

Chame esse método para arredondar a moeda para um número especificado de casas decimais.

```
HRESULT Roundint nDecimals);
```

### <a name="parameters"></a>Parâmetros

*nDecimals*<br/>
O número de dígitos para o `m_currency` qual será arredondado, no intervalo de 0 a 4.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#52](../../atl/codesnippet/cpp/ccomcurrency-class_19.cpp)]

##  <a name="setfraction"></a>  CComCurrency::SetFraction

Chame esse método para definir o componente fracionário de um `CComCurrency` objeto.

```
HRESULT SetFraction(SHORT nFraction);
```

### <a name="parameters"></a>Parâmetros

*nFraction*<br/>
O valor a ser atribuído ao componente fracionário do membro de `m_currency` dados. O sinal do componente fracionário deve ser o mesmo que o componente de inteiro, e o valor deve estar no intervalo de-9999 (CY_MIN_FRACTION) a + 9999 (CY_MAX_FRACTION).

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#53](../../atl/codesnippet/cpp/ccomcurrency-class_20.cpp)]

##  <a name="setinteger"></a>  CComCurrency::SetInteger

Chame esse método para definir o componente de inteiro de `CComCurrency` um objeto.

```
HRESULT SetInteger(LONGLONG nInteger);
```

### <a name="parameters"></a>Parâmetros

*nInteger*<br/>
O valor a ser atribuído ao componente de inteiro do membro `m_currency` de dados. O sinal do componente inteiro deve corresponder ao sinal do componente fracionário existente.

*nInteger* deve estar no intervalo de CY_MIN_INTEGER a CY_MAX_INTEGER inclusivo. Esses valores são definidos em atlcur. h.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#54](../../atl/codesnippet/cpp/ccomcurrency-class_21.cpp)]

## <a name="see-also"></a>Consulte também

[Classe COleCurrency](../../mfc/reference/colecurrency-class.md)<br/>
[MOEDA](/windows/win32/api/wtypes/ns-wtypes-cy)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
