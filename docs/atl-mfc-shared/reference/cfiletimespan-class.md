---
title: Classe CFileTimeSpan
ms.date: 10/18/2018
f1_keywords:
- CFileTimeSpan
- ATLTIME/ATL::CFileTimeSpan
- ATLTIME/ATL::CFileTimeSpan::CFileTimeSpan
- ATLTIME/ATL::CFileTimeSpan::GetTimeSpan
- ATLTIME/ATL::CFileTimeSpan::SetTimeSpan
helpviewer_keywords:
- shared classes, CFileTimeSpan
- CFileTimeSpan class
ms.assetid: 5856fb39-9c82-4027-8ccf-8760890491ec
ms.openlocfilehash: f9bb42ba4c142f671a83dcfa7e99cff940fff047
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491287"
---
# <a name="cfiletimespan-class"></a>Classe CFileTimeSpan

Essa classe fornece métodos para gerenciar valores de data e hora relativos associados a um arquivo.

## <a name="syntax"></a>Sintaxe

```
class CFileTimeSpan
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTimeSpan::CFileTimeSpan](#cfiletimespan)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTimeSpan::GetTimeSpan](#gettimespan)|Chame esse método para recuperar o período de tempo do `CFileTimeSpan` objeto.|
|[CFileTimeSpan::SetTimeSpan](#settimespan)|Chame esse método para definir o período de tempo do `CFileTimeSpan` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CFileTimeSpan:: Operator](#operator_-)|Executa a subtração em `CFileTimeSpan` um objeto.|
|[CFileTimeSpan:: Operator! =](#operator_neq)|Compara dois objetos `CFileTimeSpan` quanto à desigualdade.|
|[CFileTimeSpan:: Operator +](#operator_add)|Executa a adição em `CFileTimeSpan` um objeto.|
|[CFileTimeSpan:: Operator + =](#operator_add_eq)|Executa a adição em `CFileTimeSpan` um objeto e atribui o resultado ao objeto atual.|
|[Operador CFileTimeSpan::&lt;](#operator_lt)|Compara dois `CFileTimeSpan` objetos para determinar o menor.|
|[Operador CFileTimeSpan::&lt;=](#operator_lt_eq)|Compara dois `CFileTimeSpan` objetos para determinar a igualdade ou o menor.|
|[CFileTimeSpan:: Operator =](#operator_eq)|O operador de atribuição.|
|[CFileTimeSpan:: Operator-=](#operator_-_eq)|Executa a subtração em `CFileTimeSpan` um objeto e atribui o resultado ao objeto atual.|
|[CFileTimeSpan:: Operator = =](#operator_eq_eq)|Compara dois objetos `CFileTimeSpan` quanto à igualdade.|
|[Operador CFileTimeSpan::&gt;](#operator_gt)|Compara dois `CFileTimeSpan` objetos para determinar o maior.|
|[Operador CFileTimeSpan::&gt;=](#operator_gt_eq)|Compara dois `CFileTimeSpan` objetos para determinar a igualdade ou o maior.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para gerenciar períodos de tempo relativos que geralmente foram encontrados ao executar operações relativas a quando um arquivo foi criado, acessado ou modificado pela última vez. Os métodos dessa classe são frequentemente usados em conjunto com objetos de [classe](../../atl-mfc-shared/reference/cfiletime-class.md) de testcfiletime.

## <a name="example"></a>Exemplo

Consulte o exemplo de [Testcfiletime:: milissegundo](../../atl-mfc-shared/reference/cfiletime-class.md#millisecond).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime. h

##  <a name="cfiletimespan"></a>  CFileTimeSpan::CFileTimeSpan

O construtor.

```
CFileTimeSpan() throw();
CFileTimeSpan(const CFileTimeSpan& span) throw();
CFileTimeSpan(LONGLONG nSpan) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan` existente.

*nSpan*<br/>
Um período de tempo em milissegundos.

### <a name="remarks"></a>Comentários

O `CFileTimeSpan` objeto pode ser criado usando um objeto `CFileTimeSpan` existente ou expresso como um valor de 64 bits. O construtor padrão define o período de tempo como 0.

##  <a name="gettimespan"></a>  CFileTimeSpan::GetTimeSpan

Chame esse método para recuperar o período de tempo do `CFileTimeSpan` objeto.

```
LONGLONG GetTimeSpan() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o período de tempo em milissegundos.

##  <a name="operator_-"></a>  CFileTimeSpan::operator -

Executa a subtração em `CFileTimeSpan` um objeto.

```
CFileTimeSpan operator-(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTimeSpan` objeto que representa o resultado da diferença entre dois intervalos de tempo.

##  <a name="operator_neq"></a>CFileTimeSpan:: Operator! =

Compara dois objetos `CFileTimeSpan` quanto à desigualdade.

```
bool operator!=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará true se o item que está sendo comparado não for igual `CFileTimeSpan` ao objeto; caso contrário, false.

##  <a name="operator_add"></a>CFileTimeSpan:: Operator +

Executa a adição em `CFileTimeSpan` um objeto.

```
CFileTimeSpan operator+(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTimeSpan` objeto que contém a soma dos dois intervalos de tempo.

##  <a name="operator_add_eq"></a>CFileTimeSpan:: Operator + =

Executa a adição em `CFileTimeSpan` um objeto e atribui o resultado ao objeto atual.

```
CFileTimeSpan& operator+=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CFileTimeSpan` atualizado que contém a soma dos dois intervalos de tempo.

##  <a name="operator_lt"></a>Operador CFileTimeSpan::&lt;

Compara dois `CFileTimeSpan` objetos para determinar o menor.

```
bool operator<(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o primeiro objeto for menor (ou seja, representa um período de tempo menor) do que o segundo; caso contrário, FALSE.

##  <a name="operator_lt_eq"></a>Operador CFileTimeSpan::&lt;=

Compara dois `CFileTimeSpan` objetos para determinar a igualdade ou o menor.

```
bool operator<=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o primeiro objeto for menor que (ou seja, representa um período de tempo menor) ou igual ao segundo, caso contrário, FALSE.

##  <a name="operator_eq"></a>  CFileTimeSpan::operator =

O operador de atribuição.

```
CFileTimeSpan& operator=(const CFileTimeSpan& span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CFileTimeSpan` atualizado.

##  <a name="operator_-_eq"></a>CFileTimeSpan:: Operator-=

Executa a subtração em `CFileTimeSpan` um objeto e atribui o resultado ao objeto atual.

```
CFileTimeSpan& operator-=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CFileTimeSpan` atualizado.

##  <a name="operator_eq_eq"></a>CFileTimeSpan:: Operator = =

Compara dois objetos `CFileTimeSpan` quanto à igualdade.

```
bool operator==(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se os objetos forem iguais; caso contrário, FALSE.

##  <a name="operator_gt"></a>Operador CFileTimeSpan::&gt;

Compara dois `CFileTimeSpan` objetos para determinar o maior.

```
bool operator>(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o primeiro objeto for maior que (ou seja, representa um período de tempo maior) do que o segundo; caso contrário, FALSE.

##  <a name="operator_gt_eq"></a>Operador CFileTimeSpan::&gt;=

Compara dois `CFileTimeSpan` objetos para determinar a igualdade ou o maior.

```
bool operator>=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o primeiro objeto for maior que (ou seja, representa um período de tempo maior) ou igual ao segundo, caso contrário, FALSE.

##  <a name="settimespan"></a>  CFileTimeSpan::SetTimeSpan

Chame esse método para definir o período de tempo do `CFileTimeSpan` objeto.

```
void SetTimeSpan(LONGLONG nSpan) throw();
```

### <a name="parameters"></a>Parâmetros

*nSpan*<br/>
O novo valor para o período de tempo em milissegundos.

## <a name="see-also"></a>Consulte também

[FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime)<br/>
[Classe CFileTime](../../atl-mfc-shared/reference/cfiletime-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
