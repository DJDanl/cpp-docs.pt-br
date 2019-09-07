---
title: Classe COleCurrency
ms.date: 08/29/2019
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
ms.openlocfilehash: fc7c64ada1100b0fc0a51670de3e8ec04b141b04
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70741641"
---
# <a name="colecurrency-class"></a>Classe COleCurrency

Encapsula o `CURRENCY` tipo de dados da automação OLE.

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
|[COleCurrency::Format](#format)|Gera uma representação de cadeia de caracteres `COleCurrency` formatada de um objeto.|
|[COleCurrency::GetStatus](#getstatus)|Obtém o status (validade) `COleCurrency` deste objeto.|
|[COleCurrency::ParseCurrency](#parsecurrency)|Lê um valor de moeda de uma cadeia de caracteres e define `COleCurrency`o valor de.|
|[COleCurrency::SetCurrency](#setcurrency)|Define o valor `COleCurrency` deste objeto.|
|[COleCurrency::SetStatus](#setstatus)|Define o status (validade) deste `COleCurrency` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator =](#operator_eq)|Copia um `COleCurrency` valor.|
|[operador +,-](#operator_plus_minus)|Adiciona, subtrai e altera o sinal de `COleCurrency` valores.|
|[operador + =,-=](#operator_plus_minus_eq)|Adiciona e subtrai um `COleCurrency` valor `COleCurrency` desse objeto.|
|[operador */](#operator_star)|Dimensiona um `COleCurrency` valor por um valor inteiro.|
|[operador * =,/=](#operator_star_div_eq)|Dimensiona esse `COleCurrency` valor por um valor inteiro.|
|[< de < do operador](#operator_stream)|Gera um `COleCurrency` valor para `CArchive` ou `CDumpContext`.|
|[> de > do operador](#operator_stream)|Insere um `COleCurrency` objeto de `CArchive`.|
|[MOEDA do operador](#operator_currency)|Converte um `COleCurrency` valor em uma moeda.|
|[operator ==, <, <=, etc.](#colecurrency_relational_operators)|Compara dois `COleCurrency` valores.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCurrency::m_cur](#m_cur)|Contém a moeda subjacente deste `COleCurrency` objeto.|
|[COleCurrency::m_status](#m_status)|Contém o status `COleCurrency` deste objeto.|

## <a name="remarks"></a>Comentários

`COleCurrency`Não tem uma classe base.

A moeda é implementada como um valor inteiro de complemento de 8 bytes de dois, dimensionado por 10.000. Isso fornece um número de ponto fixo com 15 dígitos à esquerda do ponto decimal e 4 dígitos à direita. O tipo de dados CURRENCY é extremamente útil para cálculos que envolvem dinheiro ou para qualquer cálculo de ponto fixo em que a precisão é importante. É um dos tipos possíveis para o `VARIANT` tipo de dados da automação OLE.

`COleCurrency`também implementa algumas operações aritméticas básicas para esse tipo de ponto fixo. As operações com suporte foram selecionadas para controlar os erros de arredondamento que ocorrem durante cálculos de ponto fixo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleCurrency`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

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
Um valor de moeda a ser copiado para `COleCurrency` o novo objeto.

*curSrc*<br/>
Um objeto `COleCurrency` existente a ser copiado para o `COleCurrency` novo objeto.

*varSrc*<br/>
Uma estrutura `VARIANT` de dados existente (possivelmente `COleVariant` um objeto) a ser convertida em um valor de moeda (VT_CY) e copiada para o novo `COleCurrency` objeto.

*nunits*, *nFractionalUnits* indicam as unidades e a parte fracionária (em 1/10000) do valor a ser copiado para o novo `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores criam novos `COleCurrency` objetos inicializados para o valor especificado. Segue uma breve descrição de cada um desses construtores. Salvo indicação em contrário, o status do novo `COleCurrency` item é definido como válido.

- COleCurrency () constrói um `COleCurrency` objeto inicializado como 0 (zero).

- COleCurrency (`cySrc`) constrói um `COleCurrency` objeto a partir de um valor de [moeda](/windows/win32/api/wtypes/ns-wtypes-cy~r1) .

- COleCurrency (`curSrc`) constrói um objeto `COleCurrency` a partir de um `COleCurrency` objeto existente. O novo objeto tem o mesmo status que o objeto de origem.

- COleCurrency (`varSrc`) constrói um `COleCurrency` objeto. Tenta converter uma estrutura de [variante](/windows/win32/api/oaidl/ns-oaidl-variant) ou `COleVariant` um objeto em um valor de moeda (VT_CY). Se essa conversão for bem-sucedida, o valor convertido será copiado para o `COleCurrency` novo objeto. Se não for, o valor do `COleCurrency` objeto será definido como zero (0) e seu status como inválido.

- `COleCurrency(`o objeto nunits`) Constructs a `nFractionalUnitsCOleCurrency' dos componentes numéricos especificados.`, ` Se o valor absoluto da parte fracionária for maior que 10.000, o ajuste apropriado será feito nas unidades. Observe que as unidades e a parte fracionária são especificadas por valores longos assinados.

Para obter mais informações, consulte as entradas de [moeda](/windows/win32/api/wtypes/ns-wtypes-cy~r1) e [variante](/windows/win32/api/oaidl/ns-oaidl-variant) no SDK do Windows.

### <a name="example"></a>Exemplo

Os exemplos a seguir mostram os efeitos dos construtores de zero parâmetro e de dois parâmetros:

[!code-cpp[NVC_MFCOleContainer#10](../../mfc/codesnippet/cpp/colecurrency-class_1.cpp)]

##  <a name="format"></a>COleCurrency:: Format

Chame essa função de membro para criar uma representação formatada do valor de moeda.

```
CString Format(DWORD  dwFlags = 0, LCID  lcid = LANG_USER_DEFAULT) const;
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Indica os sinalizadores para as configurações de localidade. Somente o sinalizador a seguir é relevante para a moeda:

- LOCALE_NOUSEROVERRIDE Use as configurações de localidade padrão do sistema, em vez de configurações de usuário personalizadas.

*lcid*<br/>
Indica a ID de localidade a ser usada para a conversão.

### <a name="return-value"></a>Valor de retorno

Uma `CString` que contém o valor da moeda formatada.

### <a name="remarks"></a>Comentários

Ele formata o valor usando as especificações do idioma local (IDs de localidade). Um símbolo de moeda não está incluído no valor retornado. Se o status `COleCurrency` desse objeto for nulo, o valor de retorno será uma cadeia de caracteres vazia. Se o status for inválido, a cadeia de caracteres de retorno será especificada pelo recurso de cadeia de caracteres IDS_INVALID_CURRENCY.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#11](../../mfc/codesnippet/cpp/colecurrency-class_2.cpp)]

##  <a name="getstatus"></a>  COleCurrency::GetStatus

Chame essa função de membro para obter o status (validade) de um `COleCurrency` determinado objeto.

```
CurrencyStatus GetStatus() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o status desse `COleCurrency` valor.

### <a name="remarks"></a>Comentários

O valor de retorno é definido pelo `CurrencyStatus` tipo enumerado que é definido dentro da `COleCurrency` classe.

```
enum CurrencyStatus {
    valid = 0,
    invalid = 1,
    null = 2
    };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

  - `COleCurrency::valid`Indica que este `COleCurrency` objeto é válido.

  - `COleCurrency::invalid`Indica que este `COleCurrency` objeto é inválido; ou seja, seu valor pode estar incorreto.

  - `COleCurrency::null`Indica que esse `COleCurrency` objeto é nulo, ou seja, que nenhum valor foi fornecido para esse objeto. (Isso é "NULL" no sentido do banco de dados de "sem valor", em oposição ao C++ NULL.)

O status de um `COleCurrency` objeto é inválido nos seguintes casos:

- Se seu valor for definido de uma variante ou `COleVariant` valor que não pôde ser convertido em um valor de moeda.

- Se esse objeto tiver ocorrido um estouro ou negativo durante uma operação de atribuição aritmética, por exemplo `+=` , **\* =** ou.

- Se um valor inválido foi atribuído a esse objeto.

- Se o status deste objeto foi explicitamente definido como inválido usando [SetStatus](#setstatus).

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte as seguintes funções de membro:

- [COleCurrency](#colecurrency)

- [operator =](#operator_eq)

- [operador +-](#operator_plus_minus)

- [operador + = e-=](#operator_plus_minus_eq)

- [operador */](#operator_star)

- [operador * = e/=](#operator_star_div_eq)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#12](../../mfc/codesnippet/cpp/colecurrency-class_3.cpp)]

##  <a name="m_cur"></a>  COleCurrency::m_cur

A estrutura de [moeda](/windows/win32/api/wtypes/ns-wtypes-cy~r1) subjacente para `COleCurrency` este objeto.

### <a name="remarks"></a>Comentários

> [!CAUTION]
>  Alterar o valor na `CURRENCY` estrutura acessado pelo ponteiro retornado por essa função alterará o valor `COleCurrency` desse objeto. Ele não altera o status `COleCurrency` desse objeto.

Para obter mais informações, consulte a entrada de [moeda](/windows/win32/api/wtypes/ns-wtypes-cy~r1) na SDK do Windows.

##  <a name="m_status"></a>  COleCurrency::m_status

O tipo desse membro de dados é o tipo `CurrencyStatus`enumerado, que é definido dentro da `COleCurrency` classe.

```
enum CurrencyStatus{
    valid = 0,
    invalid = 1,
    null = 2,
};
```

### <a name="remarks"></a>Comentários

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleCurrency::valid`Indica que este `COleCurrency` objeto é válido.

- `COleCurrency::invalid`Indica que este `COleCurrency` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleCurrency::null`Indica que esse `COleCurrency` objeto é nulo, ou seja, que nenhum valor foi fornecido para esse objeto. (Isso é "NULL" no sentido do banco de dados de "sem valor", em oposição ao C++ NULL.)

O status de um `COleCurrency` objeto é inválido nos seguintes casos:

- Se seu valor for definido de uma variante ou `COleVariant` valor que não pôde ser convertido em um valor de moeda.

- Se esse objeto tiver ocorrido um estouro ou negativo durante uma operação de atribuição aritmética, por exemplo `+=` , **\* =** ou.

- Se um valor inválido foi atribuído a esse objeto.

- Se o status deste objeto foi explicitamente definido como inválido usando [SetStatus](#setstatus).

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte as seguintes funções de membro:

- [COleCurrency](#colecurrency)

- [operator =](#operator_eq)

- [operador +,-](#operator_plus_minus)

- [operador + =,-=](#operator_plus_minus_eq)

- [operador */](#operator_star)

- [operador * =,/=](#operator_star_div_eq)

> [!CAUTION]
>  Esse membro de dados destina-se a situações de programação avançada. Você deve usar as funções membro embutido [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para obter mais precauções sobre como definir explicitamente esse membro de dados.

##  <a name="operator_eq"></a>COleCurrency:: Operator =

Esses operadores de atribuição sobrecarregados copiam o valor de moeda `COleCurrency` de origem para esse objeto.

```
const COleCurrency& operator=(CURRENCY cySrc);
const COleCurrency& operator=(const COleCurrency& curSrc);
const COleCurrency& operator=(const VARIANT& varSrc);
```

### <a name="remarks"></a>Comentários

Segue uma breve descrição de cada operador:

- **Operator = (** `cySrc` **)** o `CURRENCY` valor é copiado para `COleCurrency` o objeto e seu status é definido como válido.

- **Operator = (** `curSrc` **)** o valor e o status do operando, um objeto `COleCurrency` existente é copiado para `COleCurrency` esse objeto.

- **Operator = (** *varSrc* **)** Se a conversão `VARIANT` do valor (ou objeto [COleVariant](../../mfc/reference/colevariant-class.md) ) em uma moeda ( `VT_CY`) for bem-sucedida, o valor convertido será copiado para esse `COleCurrency` objeto e seu status será definido como válido. Se a conversão não for bem-sucedida, o valor do `COleCurrency` objeto será definido como 0 e seu status como inválido.

Para obter mais informações, consulte as entradas de [moeda](/windows/win32/api/wtypes/ns-wtypes-cy~r1) e [variante](/windows/win32/api/oaidl/ns-oaidl-variant) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#15](../../mfc/codesnippet/cpp/colecurrency-class_4.cpp)]

##  <a name="operator_plus_minus"></a>COleCurrency:: operator +,-

Esses operadores permitem adicionar e subtrair dois `COleCurrency` valores entre si e para alterar o sinal de um `COleCurrency` valor.

```
COleCurrency operator+(const COleCurrency& cur) const;
COleCurrency operator-(const COleCurrency& cur) const;
COleCurrency operator-() const;
```

### <a name="remarks"></a>Comentários

Se um dos operandos for nulo, o status do valor resultante `COleCurrency` será NULL.

Se a operação aritmética ultrapassar, o valor resultante `COleCurrency` será inválido.

Se o operando for inválido e o outro não for nulo, o status do valor resultante `COleCurrency` será inválido.

Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte a variável de membro [m_status](#m_status) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#16](../../mfc/codesnippet/cpp/colecurrency-class_5.cpp)]

##  <a name="operator_plus_minus_eq"></a>COleCurrency:: operator + =,-=

Permite adicionar e subtrair um `COleCurrency` valor de e para esse `COleCurrency` objeto.

```
const COleCurrency& operator+=(const COleCurrency& cur);
const COleCurrency& operator-=(const COleCurrency& cur);
```

### <a name="remarks"></a>Comentários

Se um dos operandos for nulo, o status desse `COleCurrency` objeto será definido como nulo.

Se a operação aritmética ultrapassar, o status `COleCurrency` desse objeto será definido como inválido.

Se um dos operandos for inválido e o outro não for nulo, o status `COleCurrency` desse objeto será definido como inválido.

Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte a variável de membro [m_status](#m_status) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#17](../../mfc/codesnippet/cpp/colecurrency-class_6.cpp)]

##  <a name="operator_star"></a>COleCurrency:: Operator \* e/

Permite que você dimensione `COleCurrency` um valor por um valor integral.

```
COleCurrency operator*(long nOperand) const;
COleCurrency operator/(long nOperand) const;
```

### <a name="remarks"></a>Comentários

Se o `COleCurrency` operando for nulo, o status do valor resultante `COleCurrency` será NULL.

Se a operação aritmética estourar ou estourar, o status do valor resultante `COleCurrency` será inválido.

Se o `COleCurrency` operando for inválido, o status do valor resultante `COleCurrency` será inválido.

Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte a variável de membro [m_status](#m_status) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#18](../../mfc/codesnippet/cpp/colecurrency-class_7.cpp)]

##  <a name="operator_star_div_eq"></a>  COleCurrency::operator \*=, /=

Permite que você dimensione `COleCurrency` esse valor por um valor integral.

```
const COleCurrency& operator*=(long nOperand);
const COleCurrency& operator/=(long nOperand);
```

### <a name="remarks"></a>Comentários

Se o `COleCurrency` operando for nulo, o status `COleCurrency` desse objeto será definido como nulo.

Se a operação aritmética ultrapassar, o status `COleCurrency` desse objeto será definido como inválido.

Se o `COleCurrency` operando for inválido, o status `COleCurrency` desse objeto será definido como inválido.

Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte a variável de membro [m_status](#m_status) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#19](../../mfc/codesnippet/cpp/colecurrency-class_8.cpp)]

##  <a name="operator_stream"></a>&lt; Operador&lt;COleCurrency::,&gt;&gt;

Dá suporte ao despejo de diagnóstico e ao armazenamento em um arquivo.

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

O operador Extraction ( **>>** ) dá suporte ao carregamento de um arquivo morto.

##  <a name="operator_currency"></a>MOEDA do operador COleCurrency:: Operator

Retorna uma `CURRENCY` estrutura cujo valor é copiado `COleCurrency` deste objeto.

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
Indica sinalizadores para configurações de localidade, possivelmente o seguinte sinalizador:

- LOCALE_NOUSEROVERRIDE Use as configurações de localidade padrão do sistema, em vez de configurações de usuário personalizadas.

*lcid*<br/>
Indica a ID de localidade a ser usada para a conversão.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a cadeia de caracteres foi convertida com êxito em um valor de moeda, caso contrário 0.

### <a name="remarks"></a>Comentários

Ele usa as especificações de idioma local (IDs de localidade) para o significado de caracteres não numéricos na cadeia de caracteres de origem.

Para obter uma discussão sobre valores de ID de localidade, consulte [suporte a vários idiomas](/previous-versions/windows/desktop/automat/supporting-multiple-national-languages).

Se a cadeia de caracteres tiver sido convertida com êxito em um valor de moeda `COleCurrency` , o valor desse objeto será definido para esse valor e seu status como válido.

Se a cadeia de caracteres não puder ser convertida em um valor de moeda ou se houvesse um estouro numérico, o `COleCurrency` status desse objeto será inválido.

Se a conversão da cadeia de caracteres falhou devido a erros de alocação de memória, essa função gera um [CMemoryException](../../mfc/reference/cmemoryexception-class.md). Em qualquer outro Estado de erro, essa função gera um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#13](../../mfc/codesnippet/cpp/colecurrency-class_9.cpp)]

##  <a name="colecurrency_relational_operators"></a>Operadores relacionais do COleCurrency

Compare dois valores de moeda e retorne diferente de zero se a condição for verdadeira; caso contrário, 0.

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
>  O valor de retorno das **<** operações de ordenação ( **>** , **>=** **\< =** ,,) será indefinido se o status de um dos operandos for nulo ou inválido. Os operadores de igualdade `==`( `!=`,) consideram o status dos operandos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#20](../../mfc/codesnippet/cpp/colecurrency-class_10.cpp)]

##  <a name="setcurrency"></a>  COleCurrency::SetCurrency

Chame essa função de membro para definir as unidades e parte fracionária deste `COleCurrency` objeto.

```
void SetCurrency(
    long nUnits,
    long nFractionalUnits);
```

### <a name="parameters"></a>Parâmetros

*nunits*, *nFractionalUnits* indicam as unidades e a parte fracionária (em 1/10000) do valor a ser copiado para esse `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

Se o valor absoluto da parte fracionária for maior que 10.000, o ajuste apropriado será feito nas unidades, conforme mostrado no terceiro dos exemplos a seguir.

Observe que as unidades e a parte fracionária são especificadas por valores longos assinados. O quarto dos exemplos a seguir mostra o que acontece quando os parâmetros têm sinais diferentes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#14](../../mfc/codesnippet/cpp/colecurrency-class_11.cpp)]

##  <a name="setstatus"></a>  COleCurrency::SetStatus

Chame essa função de membro para definir o status (validade) `COleCurrency` deste objeto.

```
void SetStatus(CurrencyStatus  status  );
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O novo status deste `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

O valor do parâmetro *status* é definido pelo `CurrencyStatus` tipo enumerado, que é definido dentro da `COleCurrency` classe.

```
enum CurrencyStatus {
    valid = 0,
    invalid = 1,
    null = 2
    };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleCurrency::valid`Indica que este `COleCurrency` objeto é válido.

- `COleCurrency::invalid`Indica que este `COleCurrency` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleCurrency::null`Indica que esse `COleCurrency` objeto é nulo, ou seja, que nenhum valor foi fornecido para esse objeto. (Isso é "NULL" no sentido do banco de dados de "sem valor", em oposição ao C++ NULL.)

> [!CAUTION]
>  Essa função é para situações de programação avançada. Essa função não altera os dados neste objeto. Com mais frequência, ele será usado para definir o status como nulo ou inválido. Observe que o operador de atribuição ( [operador =](#operator_eq)) e [SetCurrency](#setcurrency) definem o status como do objeto com base no (s) valor (es) de origem.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleVariant](../../mfc/reference/colevariant-class.md)
