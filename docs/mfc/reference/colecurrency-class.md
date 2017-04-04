---
title: Classe COleCurrency | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- fixed-point numbers
- numbers, fixed-point
- CURRENCY
- COleCurrency class
ms.assetid: 3a36e345-303f-46fb-a57c-858274378a8d
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 38dbd45818f53430db37bb5807c255494c4a9896
ms.lasthandoff: 02/25/2017

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
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleCurrency::Format](#format)|Gera uma representação de cadeia de caracteres formatada de um `COleCurrency` objeto.|  
|[COleCurrency::GetStatus](#getstatus)|Obtém o status (validade) deste `COleCurrency` objeto.|  
|[COleCurrency::ParseCurrency](#parsecurrency)|Lê um **moeda** o valor de uma cadeia de caracteres e define o valor de `COleCurrency`.|  
|[COleCurrency::SetCurrency](#setcurrency)|Define o valor desse `COleCurrency` objeto.|  
|[COleCurrency::SetStatus](#setstatus)|Define o status (validade) para este `COleCurrency` objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador =](#operator_eq)|Copia uma `COleCurrency` valor.|  
|[operador +, -](#operator_plus_minus)|Adiciona, subtrai e altera o sinal de `COleCurrency` valores.|  
|[operador + =-=](#operator_plus_minus_eq)|Adiciona e subtrai um `COleCurrency` valor desse `COleCurrency` objeto.|  
|[operador * /](#operator_star)|Dimensiona um `COleCurrency` valor por um valor inteiro.|  
|[operador * =, / =](#operator_star_div_eq)|Isso é dimensionado `COleCurrency` valor por um valor inteiro.|  
|[operador](#operator_stream)|Saídas um `COleCurrency` valor `CArchive` ou `CDumpContext`.|  
|[operador >>](#operator_stream)|Entradas um `COleCurrency` de objeto `CArchive`.|  
|[operador de moeda](#operator_currency)|Converte um `COleCurrency` valor em uma **moeda**.|  
|[operador = =,<,></,><=,></=,>](#colecurrency_relational_operators)|Compara dois `COleCurrency` valores.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleCurrency::m_cur](#m_cur)|Contém subjacente **moeda** para este `COleCurrency` objeto.|  
|[COleCurrency::m_status](#m_status)|Contém o status desse `COleCurrency` objeto.|  
  
## <a name="remarks"></a>Comentários  
 **COleCurrency** não tem uma classe base.  
  
 **MOEDA** é implementado como um valor inteiro de complemento de dois dimensionado por 10.000 pelo 8 bytes. Isso fornece um número de ponto fixo com 15 dígitos à esquerda da vírgula decimal e 4 dígitos à direita. O **moeda** tipo de dados é extremamente útil para cálculos que envolvem dinheiro ou para qualquer cálculo de ponto fixo em que a precisão é importante. É um dos tipos possíveis para o `VARIANT` tipo de dados de automação OLE.  
  
 **COleCurrency** também implementa algumas operações aritméticas básicas para esse tipo de ponto fixo. As operações com suporte foram selecionadas para controlar os erros de arredondamento que ocorrem durante os cálculos de ponto fixo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `COleCurrency`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="colecurrency"></a>COleCurrency::COleCurrency  
 Constrói uma **COleCurrency** objeto.  
  
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
 `cySrc`  
 A **moeda** valor a ser copiado para o novo **COleCurrency** objeto.  
  
 `curSrc`  
 Existente **COleCurrency** o objeto a ser copiado para o novo **COleCurrency** objeto.  
  
 *varSrc*  
 Existente **VARIANT** estrutura de dados (possivelmente um `COleVariant` objeto) a ser convertido em um valor de moeda ( `VT_CY`) e copiados para o novo **COleCurrency** objeto.  
  
 `nUnits`, `nFractionalUnits`  
 Indicar as unidades e a parte fracionária (em 1/10, milhares) o valor a ser copiado para o novo **COleCurrency** objeto.  
  
### <a name="remarks"></a>Comentários  
 Todos esses construtores criar novos **COleCurrency** objetos inicializados com o valor especificado. Segue uma breve descrição de cada um desses construtores. Salvo indicação em contrário, o status da nova **COleCurrency** item é definido como válido.  
  
- Construções COleCurrency() uma **COleCurrency** objeto inicializado como 0 (zero).  
  
- COleCurrency (`cySrc`) constrói uma **COleCurrency** de objeto um [moeda](http://msdn.microsoft.com/en-us/5e81273c-7289-45c7-93c0-32c1553f708e) valor.  
  
- COleCurrency (`curSrc`) constrói uma **COleCurrency** objeto a partir de um existente **COleCurrency** objeto. O novo objeto tem o mesmo status que o objeto de origem.  
  
- COleCurrency (`varSrc`) constrói uma **COleCurrency** objeto. Tenta converter um [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) estrutura ou `COleVariant` objeto em uma moeda ( `VT_CY`) valor. Se essa conversão for bem-sucedida, o valor convertido é copiado no novo **COleCurrency** objeto. Se não estiver, o valor da **COleCurrency** objeto é definido como zero (0) e seu status inválido.  
  
- `COleCurrency(`nUnits`, `'nFractionalUnits) constrói uma **COleCurrency** objeto dos componentes numéricos especificados. Se o valor absoluto da parte fracionária é maior que 10.000, o ajuste apropriado é feito para as unidades. Observe que as unidades e a parte fracionária são especificados por valores longos assinados.  
  
 Para obter mais informações, consulte o [moeda](http://msdn.microsoft.com/en-us/5e81273c-7289-45c7-93c0-32c1553f708e) e [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) entradas na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 Os exemplos a seguir mostram os efeitos dos construtores de parâmetro de zero e dois parâmetros:  
  
 [!code-cpp[NVC_MFCOleContainer n º&10;](../../mfc/codesnippet/cpp/colecurrency-class_1.cpp)]  
  
##  <a name="format"></a>COleCurrency::Format  
 Chame essa função de membro para criar uma representação formatada do valor de moeda.  
  
```  
CString Format(DWORD  dwFlags = 0, LCID  lcid = LANG_USER_DEFAULT) const; 
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Indica os sinalizadores para configurações de localidade. O seguinte sinalizador só é relevante para moeda:  
  
- **LOCALE_NOUSEROVERRIDE** usar as configurações de localidade do sistema padrão, em vez de configurações personalizadas do usuário.  
  
 `lcid`  
 Indica a ID de localidade a ser usado para a conversão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o valor de moeda formatada.  
  
### <a name="remarks"></a>Comentários  
 Formata o valor usando as especificações do idioma local (IDs de localidade). Um símbolo de moeda não é incluído no valor retornado. Se o status dessa **COleCurrency** o objeto é nulo, o valor de retorno é uma cadeia de caracteres vazia. Se o status for inválido, a cadeia de caracteres de retornada é especificada pelo recurso de cadeia de caracteres **IDS_INVALID_CURRENCY**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer n º&11;](../../mfc/codesnippet/cpp/colecurrency-class_2.cpp)]  
  
##  <a name="getstatus"></a>COleCurrency::GetStatus  
 Chame essa função de membro para obter o status (validade) de um determinado **COleCurrency** objeto.  
  
```  
CurrencyStatus GetStatus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o status desse **COleCurrency** valor.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno é definido pelo `CurrencyStatus` que é definido no tipo enumerado de **COleCurrency** classe.  
  
```  
enum CurrencyStatus {
    valid = 0,
    invalid = 1,
    null = 2
    };  
```  
  
 Para obter uma breve descrição desses valores de status, consulte a lista a seguir:  
  
- **COleCurrency::valid** indica que esse **COleCurrency** o objeto é válido.  
  
- **COleCurrency::invalid** indica que esse **COleCurrency** o objeto é inválido; isto é, seu valor pode estar incorreto.  
  
- **COleCurrency::null** indica que esse **COleCurrency** objeto é nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez do C++ **nulo**.)  
  
 O status de uma **COleCurrency** objeto é inválido nos seguintes casos:  
  
-   Se seu valor é definido de uma **VARIANT** ou `COleVariant` valor que não pôde ser convertido para um valor de moeda.  
  
-   Se esse objeto experimentou um estouro ou estouro negativo durante uma operação aritmética de atribuição, por exemplo `+=` ou ** \* = **.  
  
-   Se um valor inválido foi atribuído a esse objeto.  
  
-   Se o status desse objeto explicitamente definido como inválido usando [SetStatus](#setstatus).  
  
 Para obter mais informações sobre as operações que podem definir o status inválido, consulte as seguintes funções de membro:  
  
- [COleCurrency](#colecurrency)  
  
- [operador =](#operator_eq)  
  
- [operador + -](#operator_plus_minus)  
  
- [operador + = e-=](#operator_plus_minus_eq)  
  
- [operador * /](#operator_star)  
  
- [operador * = e =](#operator_star_div_eq)  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&#12;](../../mfc/codesnippet/cpp/colecurrency-class_3.cpp)]  
  
##  <a name="m_cur"></a>COleCurrency::m_cur  
 Subjacente [moeda](http://msdn.microsoft.com/en-us/5e81273c-7289-45c7-93c0-32c1553f708e) estrutura para isso **COleCurrency** objeto.  
  
### <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Alterando o valor de **moeda** estrutura acessada pelo ponteiro retornado por essa função alterará o valor desse **COleCurrency** objeto. Ele não altera o status deste **COleCurrency** objeto.  
  
 Para obter mais informações, consulte o [moeda](http://msdn.microsoft.com/en-us/5e81273c-7289-45c7-93c0-32c1553f708e) entrada do [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="m_status"></a>COleCurrency::m_status  
 O tipo desse membro de dados é o tipo enumerado `CurrencyStatus`, que é definido dentro do **COleCurrency** classe.  
  
```  
enum CurrencyStatus{  
    valid = 0,  
    invalid = 1,  
    null = 2,  
};  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter uma breve descrição desses valores de status, consulte a lista a seguir:  
  
- **COleCurrency::valid** indica que esse **COleCurrency** o objeto é válido.  
  
- **COleCurrency::invalid** indica que esse **COleCurrency** o objeto é inválido; isto é, seu valor pode estar incorreto.  
  
- **COleCurrency::null** indica que esse **COleCurrency** objeto é nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez do C++ **nulo**.)  
  
 O status de uma **COleCurrency** objeto é inválido nos seguintes casos:  
  
-   Se seu valor é definido de uma **VARIANT** ou `COleVariant` valor que não pôde ser convertido para um valor de moeda.  
  
-   Se esse objeto experimentou um estouro ou estouro negativo durante uma operação aritmética de atribuição, por exemplo `+=` ou ** \* = **.  
  
-   Se um valor inválido foi atribuído a esse objeto.  
  
-   Se o status desse objeto explicitamente definido como inválido usando [SetStatus](#setstatus).  
  
 Para obter mais informações sobre as operações que podem definir o status inválido, consulte as seguintes funções de membro:  
  
- [COleCurrency](#colecurrency)  
  
- [operador =](#operator_eq)  
  
- [operador +, -](#operator_plus_minus)  
  
- [operador + =-=](#operator_plus_minus_eq)  
  
- [operador * /](#operator_star)  
  
- [operador * =, / =](#operator_star_div_eq)  
  
    > [!CAUTION]
    >  Este membro de dados é para situações de programação avançadas. Você deve usar as funções de membro embutidas [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para obter mais avisos sobre definir explicitamente esse membro de dados.  
  
##  <a name="operator_eq"></a>COleCurrency::operator =  
 Esses operadores de atribuição sobrecarregados copie o valor de moeda de origem para este **COleCurrency** objeto.  
  
```  
const COleCurrency& operator=(CURRENCY cySrc);  
const COleCurrency& operator=(const COleCurrency& curSrc);  
  const COleCurrency& operator=(const VARIANT& varSrc);
```  
  
### <a name="remarks"></a>Comentários  
 Segue uma breve descrição de cada operador:  
  
- **operador = (** `cySrc` **)** o `CURRENCY` valor é copiado para o **COleCurrency** objeto e seu status é definido como válido.  
  
- **operador = (** `curSrc` **)** o valor e o status do operando, existente **COleCurrency** objeto são copiados para esse **COleCurrency** objeto.  
  
- **operador = (** *varSrc* **)** se a conversão do `VARIANT` valor (ou [COleVariant](../../mfc/reference/colevariant-class.md) objeto) em uma moeda ( `VT_CY`) for bem-sucedida, o valor convertido é copiado para esse **COleCurrency** objeto e seu status é definido como válido. Se a conversão não for bem-sucedida, o valor de **COleCurrency** objeto é definido como 0 e seu status inválido.  
  
 Para obter mais informações, consulte o [moeda](http://msdn.microsoft.com/en-us/5e81273c-7289-45c7-93c0-32c1553f708e) e [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) entradas na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&#15;](../../mfc/codesnippet/cpp/colecurrency-class_4.cpp)]  
  
##  <a name="operator_plus_minus"></a>COleCurrency::operator +, -  
 Esses operadores permitem que você adicionar e subtrair dois **COleCurrency** valores de e entre si e alterar o sinal de um **COleCurrency** valor.  
  
```  
COleCurrency operator+(const COleCurrency& cur) const;  
COleCurrency operator-(const COleCurrency& cur) const;  
COleCurrency operator-() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Se qualquer um dos operandos for null, o status de resultante **COleCurrency** valor é null.  
  
 Se a operação aritmética estourar, resultante **COleCurrency** o valor é inválido.  
  
 Se o operando é inválido e o outro é não nulo, o status de resultante **COleCurrency** o valor é inválido.  
  
 Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte o [m_status](#m_status) variável de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer n º&16;](../../mfc/codesnippet/cpp/colecurrency-class_5.cpp)]  
  
##  <a name="operator_plus_minus_eq"></a>+ = COleCurrency::operator-=  
 Permite adicionar e subtrair um **COleCurrency** valor de e para isso **COleCurrency** objeto.  
  
```  
const COleCurrency& operator+=(const COleCurrency& cur);  
const COleCurrency& operator-=(const COleCurrency& cur);
```  
  
### <a name="remarks"></a>Comentários  
 Se qualquer um dos operandos for null, o status desse **COleCurrency** objeto é definido como null.  
  
 Se a operação aritmética estoura o status desse **COleCurrency** objeto é definido para inválido.  
  
 Se qualquer um dos operandos for inválido e o outro não for nulo, o status desse **COleCurrency** objeto é definido para inválido.  
  
 Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte o [m_status](#m_status) variável de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_MFCOleContainer](../../mfc/codesnippet/cpp/colecurrency-class_6.cpp)]  
  
##  <a name="operator_star"></a>COleCurrency::operator * e /  
 Permitir que você dimensione uma **COleCurrency** valor por um valor integral.  
  
```  
COleCurrency operator*(long nOperand) const;  
COleCurrency operator/(long nOperand) const;  
```  
  
### <a name="remarks"></a>Comentários  
 Se o **COleCurrency** operando for nulo, o status de resultante **COleCurrency** valor é null.  
  
 Se a operação aritmética estouros ou estouros negativos, o status de resultante **COleCurrency** o valor é inválido.  
  
 Se o **COleCurrency** operando é inválido, o status de resultante **COleCurrency** o valor é inválido.  
  
 Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte o [m_status](#m_status) variável de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer n º&18;](../../mfc/codesnippet/cpp/colecurrency-class_7.cpp)]  
  
##  <a name="operator_star_div_eq"></a>COleCurrency::operator * =, / =  
 Permitir que você dimensione isso **COleCurrency** valor por um valor integral.  
  
```  
const COleCurrency& operator*=(long nOperand);  
const COleCurrency& operator/=(long nOperand);
```  
  
### <a name="remarks"></a>Comentários  
 Se o **COleCurrency** operando for nulo, o status desse **COleCurrency** objeto é definido como null.  
  
 Se a operação aritmética estoura o status desse **COleCurrency** objeto é definido para inválido.  
  
 Se o **COleCurrency** operando é inválido, o status desse **COleCurrency** objeto é definido para inválido.  
  
 Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte o [m_status](#m_status) variável de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[19 NVC_MFCOleContainer](../../mfc/codesnippet/cpp/colecurrency-class_8.cpp)]  
  
##  <a name="operator_stream"></a>COleCurrency::operator &lt; &lt;,&gt;&gt;  
 Oferece suporte a diagnóstico despejar e armazenar um arquivo.  
  
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
 A extração ( ** >> **) operador oferece suporte ao carregamento de um arquivo.  
  
##  <a name="operator_currency"></a>COleCurrency::operator moeda  
 Retorna um `CURRENCY` estrutura cujo valor é copiado neste **COleCurrency** objeto.  
  
```  
operator CURRENCY() const; 
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="parsecurrency"></a>COleCurrency::ParseCurrency  
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
 *lpszCurrency*  
 Um ponteiro para a cadeia de caracteres terminada em nulo que deve ser analisado.  
  
 `dwFlags`  
 Indica os sinalizadores para configurações de localidade, possivelmente o seguinte sinalizador:  
  
- **LOCALE_NOUSEROVERRIDE** usar as configurações de localidade do sistema padrão, em vez de configurações personalizadas do usuário.  
  
 `lcid`  
 Indica a ID de localidade a ser usado para a conversão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a cadeia de caracteres foi convertida com êxito em um valor de moeda, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele usa as especificações do idioma local (IDs de localidade) do significado dos caracteres não numéricos na cadeia de caracteres de origem.  
  
 Para uma discussão dos valores de ID de localidade, consulte [suporte a vários idiomas](http://msdn.microsoft.com/en-us/47dc5add-232c-4268-b977-43e12da81ede).  
  
 Se a cadeia de caracteres foi convertida com êxito em uma moeda de valor, o valor desse **COleCurrency** objeto é definido como valor e seu status válido.  
  
 Se a cadeia de caracteres não pode ser convertida em um valor monetário ou se houve um estouro numérico, o status desse **COleCurrency** o objeto é inválido.  
  
 Se a conversão de cadeia de caracteres falhou devido a erros de alocação de memória, essa função gera uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md). Em qualquer outro estado de erro, essa função gera uma [COleException](../../mfc/reference/coleexception-class.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&13;](../../mfc/codesnippet/cpp/colecurrency-class_9.cpp)]  
  
##  <a name="colecurrency_relational_operators"></a>Operadores relacionais COleCurrency  
 Compara dois valores de moeda e de retorno diferente de zero se a condição for true; Caso contrário, 0.  
  
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
>  O valor de retorno das operações de ordenação ( ** < **, ** \< = **, ** > **, ** >= **) é indefinido se o status de qualquer um dos operandos for nulo ou inválido. Os operadores de igualdade ( `==`, `!=`) considere o status dos operandos.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[20 NVC_MFCOleContainer](../../mfc/codesnippet/cpp/colecurrency-class_10.cpp)]  
  
##  <a name="setcurrency"></a>COleCurrency::SetCurrency  
 Chame essa função de membro para definir as unidades e a parte fracionária isso **COleCurrency** objeto.  
  
```  
void SetCurrency(
    long nUnits,  
    long nFractionalUnits);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nUnits`, `nFractionalUnits`  
 Indicar as unidades e a parte fracionária (em 1/10, milhares) o valor a ser copiado para isso **COleCurrency** objeto.  
  
### <a name="remarks"></a>Comentários  
 Se o valor absoluto da parte fracionária é maior que 10.000, o ajuste apropriado é feito para as unidades, como mostrado na terceira dos exemplos a seguir.  
  
 Observe que as unidades e a parte fracionária são especificados por valores longos assinados. O quarto dos exemplos a seguir mostra o que acontece quando os parâmetros têm sinais diferentes.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCOleContainer&#14;](../../mfc/codesnippet/cpp/colecurrency-class_11.cpp)]  
  
##  <a name="setstatus"></a>COleCurrency::SetStatus  
 Chame essa função de membro para definir o status (validade) deste **COleCurrency** objeto.  
  
```  
void SetStatus(CurrencyStatus  status  );
```  
  
### <a name="parameters"></a>Parâmetros  
 *status*  
 O novo status **COleCurrency** objeto.  
  
### <a name="remarks"></a>Comentários  
 O *status* o valor do parâmetro é definido pelo `CurrencyStatus` enumeração de tipo, que é definido dentro do **COleCurrency** classe.  
  
```  
enum CurrencyStatus {
    valid = 0,
    invalid = 1,
    null = 2
    };  
```  
  
 Para obter uma breve descrição desses valores de status, consulte a lista a seguir:  
  
- **COleCurrency::valid** indica que esse **COleCurrency** o objeto é válido.  
  
- **COleCurrency::invalid** indica que esse **COleCurrency** o objeto é inválido; isto é, seu valor pode estar incorreto.  
  
- **COleCurrency::null** indica que esse **COleCurrency** objeto é nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez do C++ **nulo**.)  
  
    > [!CAUTION]
    >  Essa função é para situações de programação avançadas. Essa função não alteram os dados nesse objeto. Ele costuma ser usado para definir o status como nulo ou inválido. Observe que o operador de atribuição ( [operador =](#operator_eq)) e [SetCurrency](#setcurrency) definir o status do objeto com base em valores de origem.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleVariant](../../mfc/reference/colevariant-class.md)

