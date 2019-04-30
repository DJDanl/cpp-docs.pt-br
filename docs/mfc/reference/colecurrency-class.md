---
title: Classe COleCurrency
ms.date: 11/04/2016
f1_keywords:
- COleCurrency
- AFXDISP/COleCurrency
- AFXDISP/COleCurrency::COleCurrency
- AFXDISP/COleCurrency::Format
- AFXDISP/COleCurrency::GetStatus
- AFXDISP/COleCurrency::ParseCurrency
- AFXDISP/COleCurrency::SetCurrency
- AFXDISP/COleCurrency::SetStatus
- AFXDISP/COleCurrency::m_cur
- AFXDISP/COleCurrency::m_status
helpviewer_keywords:
- COleCurrency [MFC], COleCurrency
- COleCurrency [MFC], Format
- COleCurrency [MFC], GetStatus
- COleCurrency [MFC], ParseCurrency
- COleCurrency [MFC], SetCurrency
- COleCurrency [MFC], SetStatus
- COleCurrency [MFC], m_cur
- COleCurrency [MFC], m_status
ms.assetid: 3a36e345-303f-46fb-a57c-858274378a8d
ms.openlocfilehash: 64f2b00c8a5aefe8a39c24d26af2a97625225059
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62375737"
---
# <a name="colecurrency-class"></a>Classe COleCurrency

Encapsula o `CURRENCY` tipo de dados de automação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleCurrency
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCurrency::COleCurrency](#colecurrency)|Constrói um objeto `COleCurrency`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCurrency::Format](#format)|Gera uma representação de cadeia de caracteres formatada de um `COleCurrency` objeto.|
|[COleCurrency::GetStatus](#getstatus)|Obtém o status (validade) deste `COleCurrency` objeto.|
|[COleCurrency::ParseCurrency](#parsecurrency)|Lê um valor de moeda de uma cadeia de caracteres e define o valor de `COleCurrency`.|
|[COleCurrency::SetCurrency](#setcurrency)|Define o valor deste `COleCurrency` objeto.|
|[COleCurrency::SetStatus](#setstatus)|Define o status (validade) para este `COleCurrency` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator =](#operator_eq)|Copia um `COleCurrency` valor.|
|[operador +, -](#operator_plus_minus)|Adiciona, subtrai e altera o sinal de `COleCurrency` valores.|
|[operator +=, -=](#operator_plus_minus_eq)|Adiciona e subtrai um `COleCurrency` valor deste `COleCurrency` objeto.|
|[operador * /](#operator_star)|Dimensiona um `COleCurrency` valor por um valor inteiro.|
|[operator *=, /=](#operator_star_div_eq)|Dimensiona essa `COleCurrency` valor por um valor inteiro.|
|[operador <<](#operator_stream)|Saídas de um `COleCurrency` de valor para `CArchive` ou `CDumpContext`.|
|[operador >>](#operator_stream)|Entradas de um `COleCurrency` do objeto de `CArchive`.|
|[operador de moeda](#operator_currency)|Converte um `COleCurrency` valor em uma moeda.|
|[operator ==, <, <=, etc.](#colecurrency_relational_operators)|Compara dois `COleCurrency` valores.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCurrency::m_cur](#m_cur)|Contém a moeda subjacente para este `COleCurrency` objeto.|
|[COleCurrency::m_status](#m_status)|Contém o status deste `COleCurrency` objeto.|

## <a name="remarks"></a>Comentários

`COleCurrency` não tem uma classe base.

MOEDA é implementada como um valor de inteiro de dois complementos dimensionado por 10.000 pelo 8 bytes. Isso fornece um número de ponto fixo com 15 dígitos à esquerda do ponto decimal e 4 dígitos à direita. O tipo de dados de moeda é extremamente útil para cálculos que envolvem dinheiro, ou para qualquer cálculo de ponto fixo em que a precisão é importante. É um dos tipos possíveis para o `VARIANT` tipo de dados de automação OLE.

`COleCurrency` também implementa algumas operações aritméticas básicas para esse tipo de ponto fixo. As operações com suporte foram selecionadas para controlar o arredondamento de erros que ocorrem durante os cálculos de ponto fixo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleCurrency`

## <a name="requirements"></a>Requisitos

**Header:** afxdisp.h

##  <a name="colecurrency"></a>  COleCurrency::COleCurrency

Constrói um objeto `COleCurrency`.

```
COleCurrency();
COleCurrency(CURRENCY cySrc);
  COleCurrency(const COleCurrency& curSrc);
COleCurrency(const VARIANT& varSrc);

COleCurrency(
    long nUnits,
    long nFractionalUnits);
```

### <a name="parameters"></a>Parâmetros

*cySrc*<br/>
Um valor de moeda a ser copiado para o novo `COleCurrency` objeto.

*curSrc*<br/>
Um existente `COleCurrency` o objeto a ser copiado para o novo `COleCurrency` objeto.

*varSrc*<br/>
Um existente `VARIANT` estrutura de dados (possivelmente um `COleVariant` objeto) a ser convertido em um valor de moeda (VT_CY) e copiado no novo `COleCurrency` objeto.

*nUnits*, *nFractionalUnits* indicar as unidades e a parte fracionária (em 1/10, milhares) do valor a ser copiado para o novo `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores criam novos `COleCurrency` objetos inicializados ao valor especificado. Segue uma breve descrição de cada um desses construtores. A menos que indicado o contrário, o status da nova `COleCurrency` item é definido como válido.

- Construções de COleCurrency() um `COleCurrency` objeto inicializado como 0 (zero).

- COleCurrency (`cySrc`) constrói uma `COleCurrency` do objeto de uma [moeda](/windows/desktop/api/wtypes/ns-wtypes-tagcy) valor.

- COleCurrency (`curSrc`) constrói uma `COleCurrency` objeto de uma já existente `COleCurrency` objeto. O novo objeto tem o mesmo status que o objeto de origem.

- COleCurrency (`varSrc`) constrói uma `COleCurrency` objeto. Tenta converter um [VARIANT](/windows/desktop/api/oaidl/ns-oaidl-tagvariant) estrutura ou `COleVariant` objeto como um valor de moeda (VT_CY). Se essa conversão for bem-sucedida, o valor convertido é copiado no novo `COleCurrency` objeto. Se não estiver, o valor da `COleCurrency` objeto é definido como zero (0) e seu status para inválida.

- `COleCurrency(`nUnits`, `nFractionalUnits`) Constructs a `COleCurrency' objeto dos componentes numéricos especificados. Se o valor absoluto da parte fracionária é maior que 10.000, o ajuste apropriado é feito para as unidades. Observe que as unidades e a parte fracionária são especificados por valores longo com sinal.

Para obter mais informações, consulte o [moeda](/windows/desktop/api/wtypes/ns-wtypes-tagcy) e [VARIANT](/windows/desktop/api/oaidl/ns-oaidl-tagvariant) entradas no SDK do Windows.

### <a name="example"></a>Exemplo

Os exemplos a seguir mostram os efeitos dos construtores de parâmetro de zero e dois parâmetros:

[!code-cpp[NVC_MFCOleContainer#10](../../mfc/codesnippet/cpp/colecurrency-class_1.cpp)]

##  <a name="format"></a>  COleCurrency::Format

Chame essa função de membro para criar uma representação formatada do valor de moeda.

```
CString Format(DWORD  dwFlags = 0, LCID  lcid = LANG_USER_DEFAULT) const;
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Indica os sinalizadores para as configurações de localidade. O seguinte sinalizador só é relevante para moeda:

- LOCALE_NOUSEROVERRIDE usar as configurações de localidade do sistema padrão, em vez de configurações do usuário personalizadas.

*lcid*<br/>
Indica a ID de localidade a ser usado para a conversão.

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém o valor de moeda formatada.

### <a name="remarks"></a>Comentários

Formata o valor usando as especificações de idioma local (IDs de localidade). Um símbolo de moeda não está incluído no valor retornado. Se o status deste `COleCurrency` objeto for nulo, o valor retornado é uma cadeia de caracteres vazia. Se o status for inválido, a cadeia de caracteres de retornada é especificada pelo recurso de cadeia de caracteres IDS_INVALID_CURRENCY.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#11](../../mfc/codesnippet/cpp/colecurrency-class_2.cpp)]

##  <a name="getstatus"></a>  COleCurrency::GetStatus

Chame essa função de membro para obter o status (validade) de um determinado `COleCurrency` objeto.

```
CurrencyStatus GetStatus() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o status deste `COleCurrency` valor.

### <a name="remarks"></a>Comentários

O valor de retorno é definido pela `CurrencyStatus` que é definido dentro do tipo enumerado de `COleCurrency` classe.

```
enum CurrencyStatus {
    valid = 0,
    invalid = 1,
    null = 2
    };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

  - `COleCurrency::valid` Indica que este `COleCurrency` objeto é válido.

  - `COleCurrency::invalid` Indica que este `COleCurrency` objeto é inválido; ou seja, seu valor pode estar incorreto.

  - `COleCurrency::null` Indica que este `COleCurrency` objeto for nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez de nulo do C++)

O status de um `COleCurrency` objeto é inválido nos seguintes casos:

- Se seu valor é definido de uma VARIANTE ou `COleVariant` valor que não pôde ser convertido para um valor de moeda.

- Se esse objeto experimentou um estouro ou estouro negativo durante uma operação aritmética de atribuição, por exemplo `+=` ou **\* =**.

- Se um valor inválido foi atribuído a esse objeto.

- Se o status desse objeto foi definido explicitamente como inválidos usando [SetStatus](#setstatus).

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte as seguintes funções de membro:

- [COleCurrency](#colecurrency)

- [operator =](#operator_eq)

- [operador + -](#operator_plus_minus)

- [Operator + = e =](#operator_plus_minus_eq)

- [operator * /](#operator_star)

- [operador * = e =](#operator_star_div_eq)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#12](../../mfc/codesnippet/cpp/colecurrency-class_3.cpp)]

##  <a name="m_cur"></a>  COleCurrency::m_cur

Subjacente [moeda](/windows/desktop/api/wtypes/ns-wtypes-tagcy) estrutura para este `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

> [!CAUTION]
>  Alterando o valor na `CURRENCY` estrutura acessada pelo ponteiro retornado por essa função será alterado o valor deste `COleCurrency` objeto. Ele não altera o status deste `COleCurrency` objeto.

Para obter mais informações, consulte o [moeda](/windows/desktop/api/wtypes/ns-wtypes-tagcy) entrada no SDK do Windows.

##  <a name="m_status"></a>  COleCurrency::m_status

O tipo desse membro de dados é o tipo enumerado `CurrencyStatus`, que é definido dentro de `COleCurrency` classe.

```
enum CurrencyStatus{
    valid = 0,
    invalid = 1,
    null = 2,
};
```

### <a name="remarks"></a>Comentários

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleCurrency::valid` Indica que este `COleCurrency` objeto é válido.

- `COleCurrency::invalid` Indica que este `COleCurrency` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleCurrency::null` Indica que este `COleCurrency` objeto for nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez de nulo do C++)

O status de um `COleCurrency` objeto é inválido nos seguintes casos:

- Se seu valor é definido de uma VARIANTE ou `COleVariant` valor que não pôde ser convertido para um valor de moeda.

- Se esse objeto experimentou um estouro ou estouro negativo durante uma operação aritmética de atribuição, por exemplo `+=` ou **\* =**.

- Se um valor inválido foi atribuído a esse objeto.

- Se o status desse objeto foi definido explicitamente como inválidos usando [SetStatus](#setstatus).

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte as seguintes funções de membro:

- [COleCurrency](#colecurrency)

- [operator =](#operator_eq)

- [operador +, -](#operator_plus_minus)

- [operator +=, -=](#operator_plus_minus_eq)

- [operador * /](#operator_star)

- [operator *=, /=](#operator_star_div_eq)

> [!CAUTION]
>  Este membro de dados é para situações de programação avançadas. Você deve usar as funções de membro embutidas [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para cuidados adicionais em relação à configuração explícita este membro de dados.

##  <a name="operator_eq"></a>  COleCurrency::operator =

Esses operadores de atribuição sobrecarregados copie o valor de moeda de origem para isso `COleCurrency` objeto.

```
const COleCurrency& operator=(CURRENCY cySrc);
const COleCurrency& operator=(const COleCurrency& curSrc);
  const COleCurrency& operator=(const VARIANT& varSrc);
```

### <a name="remarks"></a>Comentários

Segue uma breve descrição de cada operador:

- **operador = (** `cySrc` **)** o `CURRENCY` valor é copiado para o `COleCurrency` objeto e seu status é definido como válido.

- **operador = (** `curSrc` **)** o valor e o status do operando, um existente `COleCurrency` objeto são copiados para isso `COleCurrency` objeto.

- **operador = (** *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3* **)** se a conversão do `VARIANT` valor (ou [COleVariant](../../mfc/reference/colevariant-class.md) objeto) em uma moeda ( `VT_CY`) é for bem-sucedido, o valor convertido é copiado para esse `COleCurrency` objeto e seu status é definido como válido. Se a conversão não for bem-sucedida, o valor da `COleCurrency` objeto é definido como 0 e seu status como inválido.

Para obter mais informações, consulte o [moeda](/windows/desktop/api/wtypes/ns-wtypes-tagcy) e [VARIANT](/windows/desktop/api/oaidl/ns-oaidl-tagvariant) entradas no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#15](../../mfc/codesnippet/cpp/colecurrency-class_4.cpp)]

##  <a name="operator_plus_minus"></a>  COleCurrency::operator +, -

Esses operadores permitem que você adicionar e subtrair dois `COleCurrency` valores de e para umas das outras e para alterar o sinal de um `COleCurrency` valor.

```
COleCurrency operator+(const COleCurrency& cur) const;
COleCurrency operator-(const COleCurrency& cur) const;
COleCurrency operator-() const;
```

### <a name="remarks"></a>Comentários

Se qualquer um dos operandos for null, o status de resultante `COleCurrency` valor é nulo.

Se a operação aritmética estoura, resultante `COleCurrency` valor é inválido.

Se o operando é inválido e o outro não for nulo, o status de resultante `COleCurrency` valor é inválido.

Para obter mais informações sobre os valores de status válidos, inválidas e nulo, consulte o [m_status](#m_status) variável de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#16](../../mfc/codesnippet/cpp/colecurrency-class_5.cpp)]

##  <a name="operator_plus_minus_eq"></a>  COleCurrency::operator +=, -=

Permitem que você adicionar e subtrair um `COleCurrency` valor de e para isso `COleCurrency` objeto.

```
const COleCurrency& operator+=(const COleCurrency& cur);
const COleCurrency& operator-=(const COleCurrency& cur);
```

### <a name="remarks"></a>Comentários

Se qualquer um dos operandos for null, o status deste `COleCurrency` objeto é definido como null.

Se a operação aritmética estoura o status deste `COleCurrency` objeto é definido para inválida.

Se qualquer um dos operandos for inválido e o outro não for nulo, o status deste `COleCurrency` objeto é definido para inválida.

Para obter mais informações sobre os valores de status válidos, inválidas e nulo, consulte o [m_status](#m_status) variável de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#17](../../mfc/codesnippet/cpp/colecurrency-class_6.cpp)]

##  <a name="operator_star"></a>  COleCurrency::operator \* e /

Permitir que você dimensione um `COleCurrency` valor por um valor integral.

```
COleCurrency operator*(long nOperand) const;
COleCurrency operator/(long nOperand) const;
```

### <a name="remarks"></a>Comentários

Se o `COleCurrency` operando for nulo, o status de resultante `COleCurrency` valor é nulo.

Se a operação aritmética estouros ou estouros negativos, o status de resultante `COleCurrency` valor é inválido.

Se o `COleCurrency` operando for inválido, o status de resultante `COleCurrency` valor é inválido.

Para obter mais informações sobre os valores de status válidos, inválidas e nulo, consulte o [m_status](#m_status) variável de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#18](../../mfc/codesnippet/cpp/colecurrency-class_7.cpp)]

##  <a name="operator_star_div_eq"></a>  COleCurrency::operator \*=, /=

Permitem que você dimensioná-lo `COleCurrency` valor por um valor integral.

```
const COleCurrency& operator*=(long nOperand);
const COleCurrency& operator/=(long nOperand);
```

### <a name="remarks"></a>Comentários

Se o `COleCurrency` operando for nulo, o status deste `COleCurrency` objeto é definido como null.

Se a operação aritmética estoura o status deste `COleCurrency` objeto é definido para inválida.

Se o `COleCurrency` operando for inválido, o status deste `COleCurrency` objeto é definido para inválida.

Para obter mais informações sobre os valores de status válidos, inválidas e nulo, consulte o [m_status](#m_status) variável de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#19](../../mfc/codesnippet/cpp/colecurrency-class_8.cpp)]

##  <a name="operator_stream"></a>  COleCurrency::operator &lt;&lt;, &gt;&gt;

Dá suporte a diagnóstico despejar e armazenando em um arquivo morto.

```
friend CDumpContext& operator<<(
    CDumpContext& dc,
    COleCurrency curSrc);

friend CArchive& operator<<(
    CArchive& ar,
    COleCurrency curSrc);

friend CArchive& operator>>(
    CArchive& ar,
    COleCurrency& curSrc);
```

### <a name="remarks"></a>Comentários

A extração ( **>>**) operador oferece suporte ao carregamento de um arquivo.

##  <a name="operator_currency"></a>  COleCurrency::operator moeda

Retorna um `CURRENCY` estrutura cujo valor é copiado deste `COleCurrency` objeto.

```
operator CURRENCY() const;
```

### <a name="remarks"></a>Comentários

##  <a name="parsecurrency"></a>  COleCurrency::ParseCurrency

Chame essa função de membro para analisar uma cadeia de caracteres para ler um valor de moeda.

```
BOOL ParseCurrency(
    LPCTSTR lpszCurrency,
    DWORD dwFlags = 0,
    LCID lcid = LANG_USER_DEFAULT);

throw(CMemoryException*);
throw(COleException*);
```

### <a name="parameters"></a>Parâmetros

*lpszCurrency*<br/>
Um ponteiro para a cadeia de caracteres terminada em nulo que deve ser analisado.

*dwFlags*<br/>
Indica os sinalizadores para as configurações de localidade, possivelmente, o seguinte sinalizador:

- LOCALE_NOUSEROVERRIDE usar as configurações de localidade do sistema padrão, em vez de configurações do usuário personalizadas.

*lcid*<br/>
Indica a ID de localidade a ser usado para a conversão.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a cadeia de caracteres foi convertida com êxito para um valor de moeda, caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele usa as especificações de idioma local (IDs de localidade) para o significado dos caracteres não numéricos na cadeia de caracteres de origem.

Para uma discussão sobre os valores de ID de localidade, consulte [que dão suporte a vários idiomas](/previous-versions/windows/desktop/automat/supporting-multiple-national-languages).

Se a cadeia de caracteres foi convertida com êxito em uma moeda de valor, o valor deste `COleCurrency` objeto é definido como valor e seu status como válido.

Se a cadeia de caracteres não pôde ser convertida para um valor de moeda ou se houve um estouro numérico, o status deste `COleCurrency` objeto é inválido.

Se a conversão de cadeia de caracteres falhou devido a erros de alocação de memória, essa função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md). Em qualquer outro estado de erro, essa função gera uma [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#13](../../mfc/codesnippet/cpp/colecurrency-class_9.cpp)]

##  <a name="colecurrency_relational_operators"></a>  Operadores relacionais de COleCurrency

Comparar dois valores de moeda e de retorno diferente de zero se a condição for true; Caso contrário, 0.

```
BOOL operator==(const COleCurrency& cur) const;
BOOL operator!=(const COleCurrency& cur) const;
BOOL operator<(const COleCurrency& cur) const;
BOOL operator>(const COleCurrency& cur) const;
BOOL operator<=(const COleCurrency& cur) const;
BOOL operator>=(const COleCurrency& cur) const;
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  O valor de retorno das operações de ordenação ( **<**, **\< =**, **>**, **>=**) é indefinido se o status de qualquer um dos operandos for nulo ou inválido. Os operadores de igualdade ( `==`, `!=`) considerar o status dos operandos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#20](../../mfc/codesnippet/cpp/colecurrency-class_10.cpp)]

##  <a name="setcurrency"></a>  COleCurrency::SetCurrency

Chame essa função de membro para definir as unidades e a parte fracionária isso `COleCurrency` objeto.

```
void SetCurrency(
    long nUnits,
    long nFractionalUnits);
```

### <a name="parameters"></a>Parâmetros

*nUnits*, *nFractionalUnits* indicar as unidades e a parte fracionária (em 1/10, milhares) do valor a ser copiado para isso `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

Se o valor absoluto da parte fracionária é maior que 10.000, o ajuste apropriado é feito para as unidades, conforme mostrado no terceiro dos exemplos a seguir.

Observe que as unidades e a parte fracionária são especificados por valores longo com sinal. O quarto dos exemplos a seguir mostra o que acontece quando os parâmetros tiverem sinais diferentes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#14](../../mfc/codesnippet/cpp/colecurrency-class_11.cpp)]

##  <a name="setstatus"></a>  COleCurrency::SetStatus

Chame essa função de membro para definir o status (validade) deste `COleCurrency` objeto.

```
void SetStatus(CurrencyStatus  status  );
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O novo status `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

O *status* o valor do parâmetro é definido pela `CurrencyStatus` enumerados tipo, que é definido dentro a `COleCurrency` classe.

```
enum CurrencyStatus {
    valid = 0,
    invalid = 1,
    null = 2
    };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleCurrency::valid` Indica que este `COleCurrency` objeto é válido.

- `COleCurrency::invalid` Indica que este `COleCurrency` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleCurrency::null` Indica que este `COleCurrency` objeto for nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez de nulo do C++)

> [!CAUTION]
>  Essa função é para situações de programação avançadas. Essa função não altera os dados neste objeto. Geralmente, ele será usado para definir o status como nulo ou inválido. Observe que o operador de atribuição ( [operador =](#operator_eq)) e [SetCurrency](#setcurrency) definir o status para o objeto com base em valores de origem.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleVariant](../../mfc/reference/colevariant-class.md)
