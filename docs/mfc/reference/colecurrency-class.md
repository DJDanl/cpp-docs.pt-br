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
ms.openlocfilehash: cc69143101c5d00d4f9a689bd02abdd9596e5b53
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753925"
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
|[COleCurrency::Formato](#format)|Gera uma representação de `COleCurrency` string formatado de um objeto.|
|[COleCurrency::GetStatus](#getstatus)|Obtém o status (validade) deste `COleCurrency` objeto.|
|[COleCurrency::ParseCurrency](#parsecurrency)|Lê um valor de MOEDA a partir `COleCurrency`de uma string e define o valor de .|
|[COleCurrency::SetCurrency](#setcurrency)|Define o valor `COleCurrency` deste objeto.|
|[COleCurrency::SetStatus](#setstatus)|Define o status (validade) `COleCurrency` para este objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador =](#operator_eq)|Copia `COleCurrency` um valor.|
|[operador +, -](#operator_plus_minus)|Adiciona, subtrai e muda `COleCurrency` sinal de valores.|
|[operador +=, -=](#operator_plus_minus_eq)|Adiciona e subtrai `COleCurrency` um `COleCurrency` valor deste objeto.|
|[operador */](#operator_star)|Dimensiona `COleCurrency` um valor por um valor inteiro.|
|[operador *=, /=](#operator_star_div_eq)|Dimensiona `COleCurrency` esse valor por um valor inteiro.|
|[operador <<](#operator_stream)|Produz um `COleCurrency` valor `CArchive` `CDumpContext`para ou .|
|[operador >>](#operator_stream)|Insere `COleCurrency` um `CArchive`objeto de .|
|[operador MOEDA](#operator_currency)|Converte `COleCurrency` um valor em uma MOEDA.|
|[operador ==, <, <=, etc.](#colecurrency_relational_operators)|Compara `COleCurrency` dois valores.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleCurrency::m_cur](#m_cur)|Contém a MOEDA subjacente `COleCurrency` para este objeto.|
|[COleCurrency::m_status](#m_status)|Contém o status `COleCurrency` deste objeto.|

## <a name="remarks"></a>Comentários

`COleCurrency`não tem uma classe base.

A MOEDA é implementada como um valor inteiro de 8 bytes, dois complementos escalados por 10.000. Isso dá um número de ponto fixo com 15 dígitos à esquerda do ponto decimal e 4 dígitos para a direita. O tipo de dados CURRENCY é extremamente útil para cálculos envolvendo dinheiro, ou para qualquer cálculo de ponto fixo onde a precisão é importante. É um dos tipos possíveis `VARIANT` para o tipo de dados da automação OLE.

`COleCurrency`também implementa algumas operações aritméticas básicas para este tipo de ponto fixo. As operações suportadas foram selecionadas para controlar os erros de arredondamento que ocorrem durante os cálculos de ponto fixo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`COleCurrency`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="colecurrencycolecurrency"></a><a name="colecurrency"></a>COleCurrency::COleCurrency

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

*cisrc*<br/>
Um valor DE MOEDA a `COleCurrency` ser copiado para o novo objeto.

*curSrc*<br/>
Um objeto `COleCurrency` existente a ser copiado para o novo `COleCurrency` objeto.

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Uma estrutura `VARIANT` de dados `COleVariant` existente (possivelmente um objeto) a ser convertida em um `COleCurrency` valor de moeda (VT_CY) e copiada para o novo objeto.

*nUnidades,* *nUnidades Fracionadas* Indicar as unidades e a parte fracionada (em 1/10.000's) do valor a ser copiado para o novo `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores criam `COleCurrency` novos objetos inicializados para o valor especificado. Segue-se uma breve descrição de cada um desses construtores. Salvo observação em contrário, `COleCurrency` o status do novo item é definido como válido.

- COleCurrency() Constrói `COleCurrency` um objeto inicializado a 0 (zero).

- COleCurrency(`cySrc`) Constrói `COleCurrency` um objeto a partir de um valor [DE MOEDA.](/windows/win32/api/wtypes/ns-wtypes-cy~r1)

- COleCurrency`curSrc`( ) `COleCurrency` Constrói um objeto `COleCurrency` a partir de um objeto existente. O novo objeto tem o mesmo status do objeto de origem.

- COleCurrency`varSrc`( ) `COleCurrency` Constrói um objeto. Tentativas de [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) converter uma `COleVariant` estrutura VARIANT ou objeto para um valor de moeda (VT_CY). Se essa conversão for bem sucedida, o valor `COleCurrency` convertido será copiado para o novo objeto. Se não for, o `COleCurrency` valor do objeto é definido como zero (0) e seu status como inválido.

- COleCurrency(`nUnits` `nFractionalUnits`, ) `COleCurrency` Constrói um objeto a partir dos componentes numéricos especificados. Se o valor absoluto da parte fracionada for superior a 10.000, o ajuste adequado é feito às unidades. Observe que as unidades e a peça fracionária são especificadas por valores longos assinados.

Para obter mais informações, consulte as [entradas CURRENCY](/windows/win32/api/wtypes/ns-wtypes-cy~r1) e [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) no Windows SDK.

### <a name="example"></a>Exemplo

Os exemplos a seguir mostram os efeitos dos construtores de parâmetrozero e de dois parâmetros:

[!code-cpp[NVC_MFCOleContainer#10](../../mfc/codesnippet/cpp/colecurrency-class_1.cpp)]

## <a name="colecurrencyformat"></a><a name="format"></a>COleCurrency::Formato

Chame esta função de membro para criar uma representação formatada do valor da moeda.

```
CString Format(DWORD  dwFlags = 0, LCID  lcid = LANG_USER_DEFAULT) const;
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Indica sinalizadores para configurações locais. Apenas a seguinte bandeira é relevante para a moeda:

- LOCALE_NOUSEROVERRIDE Use as configurações locais padrão do sistema, em vez de configurações personalizadas do usuário.

*Lcid*<br/>
Indica id local para uso para a conversão.

### <a name="return-value"></a>Valor retornado

A `CString` que contém o valor da moeda formatado.

### <a name="remarks"></a>Comentários

Ele formata o valor usando as especificações de idioma local (IDs locais). Um símbolo de moeda não está incluído no valor devolvido. Se o status `COleCurrency` deste objeto for nulo, o valor de retorno será uma seqüência de string vazia. Se o status for inválido, a seqüência de retorno será especificada pelo IDS_INVALID_CURRENCY de recursos de string.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#11](../../mfc/codesnippet/cpp/colecurrency-class_2.cpp)]

## <a name="colecurrencygetstatus"></a><a name="getstatus"></a>COleCurrency::GetStatus

Chame esta função de membro para obter o `COleCurrency` status (validade) de um determinado objeto.

```
CurrencyStatus GetStatus() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o status `COleCurrency` deste valor.

### <a name="remarks"></a>Comentários

O valor de retorno `CurrencyStatus` é definido pelo tipo `COleCurrency` enumerado que é definido dentro da classe.

```
enum CurrencyStatus {
    valid = 0,
    invalid = 1,
    null = 2
    };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleCurrency::valid`Indica que `COleCurrency` este objeto é válido.

- `COleCurrency::invalid`Indica que `COleCurrency` este objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleCurrency::null`Indica que `COleCurrency` este objeto é nulo, ou seja, que nenhum valor foi fornecido para este objeto. (Isso é "nulo" no sentido de banco de dados de "não ter valor", ao contrário do C++ NULL.)

O status `COleCurrency` de um objeto é inválido nos seguintes casos:

- Se seu valor for definido `COleVariant` a partir de uma VARIANT ou valor que não poderia ser convertido em um valor de moeda.

- Se este objeto tiver experimentado um estouro ou subfluxo durante `+=` uma ** \* **operação de atribuição aritmética, por exemplo ou .

- Se um valor inválido for atribuído a este objeto.

- Se o status deste objeto foi explicitamente definido como inválido usando [SetStatus](#setstatus).

Para obter mais informações sobre operações que possam definir o status como inválido, consulte as seguintes funções de membro:

- [Colecurrency](#colecurrency)

- [operador =](#operator_eq)

- [operador + -](#operator_plus_minus)

- [operador += e -=](#operator_plus_minus_eq)

- [operador * /](#operator_star)

- [operador *= e /=](#operator_star_div_eq)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#12](../../mfc/codesnippet/cpp/colecurrency-class_3.cpp)]

## <a name="colecurrencym_cur"></a><a name="m_cur"></a>COleCurrency::m_cur

A estrutura [de](/windows/win32/api/wtypes/ns-wtypes-cy~r1) MOEDA `COleCurrency` subjacente para este objeto.

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Alterar o valor `CURRENCY` na estrutura acessada pelo ponteiro retornado `COleCurrency` por esta função mudará o valor deste objeto. Não altera o status `COleCurrency` deste objeto.

Para obter mais informações, consulte a [entrada MOEDA](/windows/win32/api/wtypes/ns-wtypes-cy~r1) no SDK do Windows.

## <a name="colecurrencym_status"></a><a name="m_status"></a>COleCurrency::m_status

O tipo deste membro de dados `CurrencyStatus`é o tipo `COleCurrency` enumerado, que é definido dentro da classe.

```
enum CurrencyStatus{
    valid = 0,
    invalid = 1,
    null = 2,
};
```

### <a name="remarks"></a>Comentários

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleCurrency::valid`Indica que `COleCurrency` este objeto é válido.

- `COleCurrency::invalid`Indica que `COleCurrency` este objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleCurrency::null`Indica que `COleCurrency` este objeto é nulo, ou seja, que nenhum valor foi fornecido para este objeto. (Isso é "nulo" no sentido de banco de dados de "não ter valor", ao contrário do C++ NULL.)

O status `COleCurrency` de um objeto é inválido nos seguintes casos:

- Se seu valor for definido `COleVariant` a partir de uma VARIANT ou valor que não poderia ser convertido em um valor de moeda.

- Se este objeto tiver experimentado um estouro ou subfluxo durante `+=` uma ** \* **operação de atribuição aritmética, por exemplo ou .

- Se um valor inválido for atribuído a este objeto.

- Se o status deste objeto foi explicitamente definido como inválido usando [SetStatus](#setstatus).

Para obter mais informações sobre operações que possam definir o status como inválido, consulte as seguintes funções de membro:

- [Colecurrency](#colecurrency)

- [operador =](#operator_eq)

- [operador +, -](#operator_plus_minus)

- [operador +=, -=](#operator_plus_minus_eq)

- [operador */](#operator_star)

- [operador *=, /=](#operator_star_div_eq)

> [!CAUTION]
> Este membro de dados é para situações avançadas de programação. Você deve usar as funções de membro inline [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para obter mais precauções sobre a definição explícita deste membro de dados.

## <a name="colecurrencyoperator-"></a><a name="operator_eq"></a>COleCurrency::operador =

Esses operadores de atribuição sobrecarregados `COleCurrency` copiam o valor da moeda de origem para este objeto.

```
const COleCurrency& operator=(CURRENCY cySrc);
const COleCurrency& operator=(const COleCurrency& curSrc);
const COleCurrency& operator=(const VARIANT& varSrc);
```

### <a name="remarks"></a>Comentários

Segue-se uma breve descrição de cada operador:

- **operador =(** `cySrc` **)** O `CURRENCY` valor é copiado para o `COleCurrency` objeto e seu status é definido como válido.

- **operador =(** `curSrc` **)** O valor e o status do operand, um objeto existente `COleCurrency` são copiados para este `COleCurrency` objeto.

- operador *=(varSrc* **operator =(** **)** Se a conversão `VARIANT` do valor (ou objeto [COleVariant)](../../mfc/reference/colevariant-class.md) para uma moeda for `VT_CY`bem `COleCurrency` sucedida, o valor convertido será copiado para este objeto e seu status será definido como válido. Se a conversão não for bem `COleCurrency` sucedida, o valor do objeto será definido como 0 e seu status como inválido.

Para obter mais informações, consulte as [entradas CURRENCY](/windows/win32/api/wtypes/ns-wtypes-cy~r1) e [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) no Windows SDK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#15](../../mfc/codesnippet/cpp/colecurrency-class_4.cpp)]

## <a name="colecurrencyoperator---"></a><a name="operator_plus_minus"></a>COleCurrency::operador +, -

Esses operadores permitem que você `COleCurrency` adicione e subtraia dois valores `COleCurrency` para e entre si e altere o sinal de um valor.

```
COleCurrency operator+(const COleCurrency& cur) const;
COleCurrency operator-(const COleCurrency& cur) const;
COleCurrency operator-() const;
```

### <a name="remarks"></a>Comentários

Se qualquer um dos operands for nulo, o status do valor resultante `COleCurrency` é nulo.

Se a operação aritmética transbordar, o valor resultante `COleCurrency` será inválido.

Se o operador for inválido e o outro não for `COleCurrency` nulo, o status do valor resultante será inválido.

Para obter mais informações sobre os valores de status válidos, inválidos e nulos, consulte a variável [membro m_status.](#m_status)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#16](../../mfc/codesnippet/cpp/colecurrency-class_5.cpp)]

## <a name="colecurrencyoperator---"></a><a name="operator_plus_minus_eq"></a>COleCurrency::operador +=, -=

Permitir que você adicione `COleCurrency` e subtraia `COleCurrency` um valor para e a partir deste objeto.

```
const COleCurrency& operator+=(const COleCurrency& cur);
const COleCurrency& operator-=(const COleCurrency& cur);
```

### <a name="remarks"></a>Comentários

Se qualquer um dos operands for `COleCurrency` nulo, o status deste objeto será definido como nulo.

Se a operação aritmética transbordar, `COleCurrency` o status deste objeto será definido como inválido.

Se um dos operands for inválido e o outro `COleCurrency` não for nulo, o status deste objeto será definido como inválido.

Para obter mais informações sobre os valores de status válidos, inválidos e nulos, consulte a variável [membro m_status.](#m_status)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#17](../../mfc/codesnippet/cpp/colecurrency-class_6.cpp)]

## <a name="colecurrencyoperator--and-"></a><a name="operator_star"></a>COleCurrency::operador \* e /

Permita que você `COleCurrency` dimensione um valor por um valor integral.

```
COleCurrency operator*(long nOperand) const;
COleCurrency operator/(long nOperand) const;
```

### <a name="remarks"></a>Comentários

Se `COleCurrency` o operador for nulo, o `COleCurrency` status do valor resultante é nulo.

Se a operação aritmética transbordar ou subvazá-lo, o status do `COleCurrency` valor resultante será inválido.

Se `COleCurrency` o operador for inválido, o `COleCurrency` status do valor resultante será inválido.

Para obter mais informações sobre os valores de status válidos, inválidos e nulos, consulte a variável [membro m_status.](#m_status)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#18](../../mfc/codesnippet/cpp/colecurrency-class_7.cpp)]

## <a name="colecurrencyoperator--"></a><a name="operator_star_div_eq"></a>COleCurrency::operator \*=, /=

Permita que você `COleCurrency` dimensione esse valor por um valor integral.

```
const COleCurrency& operator*=(long nOperand);
const COleCurrency& operator/=(long nOperand);
```

### <a name="remarks"></a>Comentários

Se `COleCurrency` o operand for nulo, o status deste `COleCurrency` objeto será definido como nulo.

Se a operação aritmética transbordar, `COleCurrency` o status deste objeto será definido como inválido.

Se `COleCurrency` o operativo for inválido, `COleCurrency` o status deste objeto será definido como inválido.

Para obter mais informações sobre os valores de status válidos, inválidos e nulos, consulte a variável [membro m_status.](#m_status)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#19](../../mfc/codesnippet/cpp/colecurrency-class_8.cpp)]

## <a name="colecurrencyoperator-ltlt-gtgt"></a><a name="operator_stream"></a>COleCurrency::operador, &lt; &lt;&gt;&gt;

Suporta dumping diagnóstico e armazenamento em um arquivo.

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

O operador **>>** de extração ( ) suporta o carregamento de um arquivo.

## <a name="colecurrencyoperator-currency"></a><a name="operator_currency"></a>COleCurrency::operator CURRENCY

Retorna `CURRENCY` uma estrutura cujo valor `COleCurrency` é copiado deste objeto.

```
operator CURRENCY() const;
```

### <a name="remarks"></a>Comentários

## <a name="colecurrencyparsecurrency"></a><a name="parsecurrency"></a>COleCurrency::ParseCurrency

Chame esta função de membro para analisar uma string para ler um valor de moeda.

```
BOOL ParseCurrency(
    LPCTSTR lpszCurrency,
    DWORD dwFlags = 0,
    LCID lcid = LANG_USER_DEFAULT);

throw(CMemoryException*);
throw(COleException*);
```

### <a name="parameters"></a>Parâmetros

*lpszMoeda*<br/>
Um ponteiro para a seqüência de terminadas nula que deve ser analisado.

*dwFlags*<br/>
Indica bandeiras para configurações locais, possivelmente a seguinte bandeira:

- LOCALE_NOUSEROVERRIDE Use as configurações locais padrão do sistema, em vez de configurações personalizadas do usuário.

*Lcid*<br/>
Indica id local para uso para a conversão.

### <a name="return-value"></a>Valor retornado

Não zero se a string foi convertida com sucesso em um valor de moeda, caso contrário 0.

### <a name="remarks"></a>Comentários

Ele usa especificações de linguagem local (IDs locais) para o significado de caracteres não numéricos na seqüência de caracteres de origem.

Para uma discussão sobre valores de ID local, consulte [Suporte a Vários Idiomas](/previous-versions/windows/desktop/automat/supporting-multiple-national-languages).

Se a string foi convertida com sucesso em `COleCurrency` um valor de moeda, o valor deste objeto será definido como esse valor e seu status para válido.

Se a string não pôde ser convertida em um valor de moeda ou se `COleCurrency` houve um estouro numérico, o status deste objeto será inválido.

Se a conversão de string falhar devido a erros de alocação de memória, esta função será lançada em [cMemoryException](../../mfc/reference/cmemoryexception-class.md). Em qualquer outro estado de erro, esta função lança uma [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#13](../../mfc/codesnippet/cpp/colecurrency-class_9.cpp)]

## <a name="colecurrency-relational-operators"></a><a name="colecurrency_relational_operators"></a>Operadores Relacionais colecurrency

Compare dois valores de moeda e devolva não zero se a condição for verdadeira; caso contrário, 0.

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
> O valor de devolução **<** ** \< **das **>=** operações de encomenda ( , , **>**) é indefinido se o status de qualquer operand é nulo ou inválido. Os operadores de `==` `!=`igualdade ( , ) consideram o status dos operands.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#20](../../mfc/codesnippet/cpp/colecurrency-class_10.cpp)]

## <a name="colecurrencysetcurrency"></a><a name="setcurrency"></a>COleCurrency::SetCurrency

Chame esta função de membro para definir `COleCurrency` as unidades e parte fracionada deste objeto.

```cpp
void SetCurrency(
    long nUnits,
    long nFractionalUnits);
```

### <a name="parameters"></a>Parâmetros

*nUnidades,* *nUnidades Fracionadas* Indicar as unidades e a parte fracionada (em 1/10.000's) do valor a ser copiado para este `COleCurrency` objeto.

### <a name="remarks"></a>Comentários

Se o valor absoluto da parte fracionada for superior a 10.000, o ajuste adequado é feito às unidades, como mostrado no terço dos exemplos a seguir.

Observe que as unidades e a peça fracionária são especificadas por valores longos assinados. O quarto dos exemplos a seguir mostra o que acontece quando os parâmetros têm sinais diferentes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#14](../../mfc/codesnippet/cpp/colecurrency-class_11.cpp)]

## <a name="colecurrencysetstatus"></a><a name="setstatus"></a>COleCurrency::SetStatus

Chame esta função de membro para definir `COleCurrency` o status (validade) deste objeto.

```cpp
void SetStatus(CurrencyStatus  status  );
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O novo status `COleCurrency` para este objeto.

### <a name="remarks"></a>Comentários

O valor do parâmetro *de status* é definido pelo `CurrencyStatus` tipo `COleCurrency` enumerado, que é definido dentro da classe.

```
enum CurrencyStatus {
    valid = 0,
    invalid = 1,
    null = 2
    };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleCurrency::valid`Indica que `COleCurrency` este objeto é válido.

- `COleCurrency::invalid`Indica que `COleCurrency` este objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleCurrency::null`Indica que `COleCurrency` este objeto é nulo, ou seja, que nenhum valor foi fornecido para este objeto. (Isso é "nulo" no sentido de banco de dados de "não ter valor", ao contrário do C++ NULL.)

> [!CAUTION]
> Esta função é para situações avançadas de programação. Esta função não altera os dados neste objeto. Na maioria das vezes, ele será usado para definir o status como nulo ou inválido. Observe que o operador de atribuição [(operador =](#operator_eq)) e [o SetCurrency](#setcurrency) definem o status do objeto com base no valor de origem(s).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleVariant](../../mfc/reference/colevariant-class.md)
