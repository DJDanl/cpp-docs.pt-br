---
title: Classe CFileTimeSpan
description: O Active Template Library (ATL) MFC e a classe CFileTimeSpan (MFC) gerenciam intervalos de tempo em unidades FILETIME.
ms.date: 01/10/2020
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
ms.openlocfilehash: 89d95759b11ff7e52c2a8fa75cf94f7b7b81fa36
ms.sourcegitcommit: c3283062ce4e382aec7f11626d358a37caf8cdbb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/13/2020
ms.locfileid: "75914388"
---
# <a name="cfiletimespan-class"></a>Classe CFileTimeSpan

Essa classe fornece métodos para gerenciar valores de data e hora relativos associados a um arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
class CFileTimeSpan
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Name|Descrição|
|----------|-----------------|
|[CFileTimeSpan::CFileTimeSpan](#cfiletimespan)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Name|Descrição|
|----------|-----------------|
|[CFileTimeSpan::GetTimeSpan](#gettimespan)|Chame esse método para recuperar o período de tempo do objeto `CFileTimeSpan`.|
|[CFileTimeSpan::SetTimeSpan](#settimespan)|Chame esse método para definir o período de tempo do objeto de `CFileTimeSpan`.|

### <a name="public-operators"></a>Operadores públicos

|Name|Descrição|
|----------|-----------------|
|[Operador CFileTimeSpan:: Operator](#operator_-)|Executa a subtração em um objeto `CFileTimeSpan`.|
|[CFileTimeSpan:: Operator! =](#operator_neq)|Compara dois objetos `CFileTimeSpan` quanto à desigualdade.|
|[CFileTimeSpan:: Operator +](#operator_add)|Executa a adição em um objeto `CFileTimeSpan`.|
|[CFileTimeSpan:: Operator + =](#operator_add_eq)|Executa a adição em um objeto `CFileTimeSpan` e atribui o resultado ao objeto atual.|
|[Operador CFileTimeSpan:: Operator &lt;](#operator_lt)|Compara dois objetos `CFileTimeSpan` para determinar o menor.|
|[CFileTimeSpan:: Operator &lt;=](#operator_lt_eq)|Compara dois objetos `CFileTimeSpan` para determinar a igualdade ou o menor.|
|[CFileTimeSpan:: Operator =](#operator_eq)|O operador de atribuição.|
|[CFileTimeSpan:: Operator-=](#operator_-_eq)|Executa a subtração em um objeto `CFileTimeSpan` e atribui o resultado ao objeto atual.|
|[CFileTimeSpan:: Operator = =](#operator_eq_eq)|Compara dois objetos `CFileTimeSpan` quanto à igualdade.|
|[Operador CFileTimeSpan:: Operator &gt;](#operator_gt)|Compara dois objetos `CFileTimeSpan` para determinar o maior.|
|[CFileTimeSpan:: Operator &gt;=](#operator_gt_eq)|Compara dois objetos `CFileTimeSpan` para determinar a igualdade ou o maior.|

## <a name="remarks"></a>Comentários

A classe `CFileTimeSpan` fornece métodos para lidar com períodos de tempo relativos nas unidades que o sistema de arquivos usa. Essas unidades são usadas com frequência em operações de arquivo, como quando um arquivo foi criado, acessado pela última vez ou modificado pela último. Os métodos dessa classe são frequentemente usados em conjunto com objetos de [classe de Testcfiletime](../../atl-mfc-shared/reference/cfiletime-class.md) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [Testcfiletime:: milissegundo](../../atl-mfc-shared/reference/cfiletime-class.md#millisecond).

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** atltime. h

## <a name="cfiletimespan"></a>CFileTimeSpan::CFileTimeSpan

O construtor.

```cpp
CFileTimeSpan() throw();
CFileTimeSpan(const CFileTimeSpan& span) throw();
CFileTimeSpan(LONGLONG nSpan) throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
Um objeto `CFileTimeSpan` existente.

\ *nSpan*
Um período de tempo em unidades FILETIME.

### <a name="remarks"></a>Comentários

O objeto `CFileTimeSpan` pode ser criado usando um objeto `CFileTimeSpan` existente ou expresso como um valor de 64 bits em unidades FILETIME de 100 nanossegundos. Para obter mais informações, consulte [Recfiletime](cfiletime-class.md). O construtor padrão define o período de tempo como 0.

## <a name="gettimespan"></a>CFileTimeSpan:: gettimespan

Chame esse método para recuperar o período de tempo do objeto `CFileTimeSpan`.

```cpp
LONGLONG GetTimeSpan() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o período de tempo em unidades FILETIME de 100 nanossegundos. Para obter mais informações, consulte [Recfiletime](cfiletime-class.md).

## <a name="operator_-"></a>  CFileTimeSpan::operator -

Executa a subtração em um objeto `CFileTimeSpan`.

```cpp
CFileTimeSpan operator-(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor retornado

Retorna um objeto `CFileTimeSpan` que representa o resultado da diferença entre dois intervalos de tempo.

## <a name="operator_neq"></a>CFileTimeSpan:: Operator! =

Compara dois objetos `CFileTimeSpan` quanto à desigualdade.

```cpp
bool operator!=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o item que está sendo comparado não for igual ao objeto `CFileTimeSpan`; caso contrário, FALSE.

## <a name="operator_add"></a>CFileTimeSpan:: Operator +

Executa a adição em um objeto `CFileTimeSpan`.

```cpp
CFileTimeSpan operator+(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor retornado

Retorna um objeto `CFileTimeSpan` que contém a soma dos dois intervalos de tempo.

## <a name="operator_add_eq"></a>CFileTimeSpan:: Operator + =

Executa a adição em um objeto `CFileTimeSpan` e atribui o resultado ao objeto atual.

```cpp
CFileTimeSpan& operator+=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor retornado

Retorna o objeto `CFileTimeSpan` atualizado que contém a soma dos dois intervalos de tempo.

## <a name="operator_lt"></a>Operador CFileTimeSpan:: Operator &lt;

Compara dois objetos `CFileTimeSpan` para determinar o menor.

```cpp
bool operator<(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o primeiro objeto for menor (ou seja, representa um período de tempo menor) do que o segundo; caso contrário, FALSE.

## <a name="operator_lt_eq"></a>CFileTimeSpan:: Operator &lt;=

Compara dois objetos `CFileTimeSpan` para determinar a igualdade ou o menor.

```cpp
bool operator<=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o primeiro objeto for menor que (ou seja, representa um período de tempo menor) ou igual ao segundo, caso contrário, FALSE.

## <a name="operator_eq"></a>  CFileTimeSpan::operator =

O operador de atribuição.

```cpp
CFileTimeSpan& operator=(const CFileTimeSpan& span) throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor retornado

Retorna o objeto `CFileTimeSpan` atualizado.

## <a name="operator_-_eq"></a>CFileTimeSpan:: Operator-=

Executa a subtração em um objeto `CFileTimeSpan` e atribui o resultado ao objeto atual.

```cpp
CFileTimeSpan& operator-=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor retornado

Retorna o objeto `CFileTimeSpan` atualizado.

## <a name="operator_eq_eq"></a>CFileTimeSpan:: Operator = =

Compara dois objetos `CFileTimeSpan` quanto à igualdade.

```cpp
bool operator==(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se os objetos forem iguais; caso contrário, FALSE.

## <a name="operator_gt"></a>Operador CFileTimeSpan:: Operator &gt;

Compara dois objetos `CFileTimeSpan` para determinar o maior.

```cpp
bool operator>(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o primeiro objeto for maior que (ou seja, representa um período de tempo maior) do que o segundo; caso contrário, FALSE.

## <a name="operator_gt_eq"></a>CFileTimeSpan:: Operator &gt;=

Compara dois objetos `CFileTimeSpan` para determinar a igualdade ou o maior.

```cpp
bool operator>=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

\ de *span*
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o primeiro objeto for maior que (ou seja, representa um período de tempo maior) ou igual ao segundo, caso contrário, FALSE.

## <a name="settimespan"></a>  CFileTimeSpan::SetTimeSpan

Chame esse método para definir o período de tempo do objeto de `CFileTimeSpan`.

```cpp
void SetTimeSpan(LONGLONG nSpan) throw();
```

### <a name="parameters"></a>Parâmetros

\ *nSpan*
O novo valor para o período de tempo em unidades FILETIME de 100 nanossegundos. Para obter mais informações, consulte [Recfiletime](cfiletime-class.md).

## <a name="see-also"></a>Veja também

\ de [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime)
[Classe de Testcfiletime](cfiletime-class.md)\
\ de [gráfico de hierarquia](../../mfc/hierarchy-chart.md)
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
