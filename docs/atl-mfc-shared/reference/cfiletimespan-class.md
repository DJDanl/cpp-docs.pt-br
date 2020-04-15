---
title: Classe CFileTimeSpan
description: A classe Active Template Library (ATL) e a Microsoft Foundation Classes (MFC) CFileTimeSpan gerenciam intervalos de tempo em unidades FILETIME.
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
ms.openlocfilehash: 87737ea1c778660a68510b484bcdfa3a4670e8ab
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317848"
---
# <a name="cfiletimespan-class"></a>Classe CFileTimeSpan

Esta classe fornece métodos para gerenciar valores relativos de data e hora associados a um arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[CFileTimeSpan::getTimespan](#gettimespan)|Chame este método para recuperar `CFileTimeSpan` o tempo do objeto.|
|[CFileTimeSpan::setTimeSpan](#settimespan)|Chame este método para definir `CFileTimeSpan` o período de tempo do objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTimeSpan::operador -](#operator_-)|Executa subtração `CFileTimeSpan` em um objeto.|
|[CFileTimeSpan::operador !=](#operator_neq)|Compara dois objetos `CFileTimeSpan` quanto à desigualdade.|
|[CFileTimeSpan::operador +](#operator_add)|Executa a `CFileTimeSpan` adição em um objeto.|
|[CFileTimeSpan::operador +=](#operator_add_eq)|Executa a `CFileTimeSpan` adição em um objeto e atribui o resultado ao objeto atual.|
|[CFileTimeSpan::operador&lt;](#operator_lt)|Compara `CFileTimeSpan` dois objetos para determinar o menor.|
|[CFileTimeSpan::operador&lt;=](#operator_lt_eq)|Compara `CFileTimeSpan` dois objetos para determinar a igualdade ou o menor.|
|[CFileTimeSpan::operador =](#operator_eq)|O operador de atribuição.|
|[CFileTimeSpan::operador -=](#operator_-_eq)|Executa subtração `CFileTimeSpan` em um objeto e atribui o resultado ao objeto atual.|
|[CFileTimeSpan::operador ==](#operator_eq_eq)|Compara dois objetos `CFileTimeSpan` quanto à igualdade.|
|[CFileTimeSpan::operador&gt;](#operator_gt)|Compara `CFileTimeSpan` dois objetos para determinar o maior.|
|[CFileTimeSpan::operador&gt;=](#operator_gt_eq)|Compara `CFileTimeSpan` dois objetos para determinar a igualdade ou o maior.|

## <a name="remarks"></a>Comentários

A `CFileTimeSpan` classe fornece métodos para lidar com períodos relativos de tempo nas unidades que o sistema de arquivos usa. Essas unidades são frequentemente usadas em operações de arquivos, como quando um arquivo foi criado, acessado pela última vez ou modificado pela última vez. Os métodos desta classe são frequentemente usados em conjunto com objetos [da classe CFileTime.](../../atl-mfc-shared/reference/cfiletime-class.md)

## <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](../../atl-mfc-shared/reference/cfiletime-class.md#millisecond).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime.h

## <a name="cfiletimespancfiletimespan"></a><a name="cfiletimespan"></a>CFileTimeSpan::CFileTimeSpan

O construtor.

```cpp
CFileTimeSpan() throw();
CFileTimeSpan(const CFileTimeSpan& span) throw();
CFileTimeSpan(LONGLONG nSpan) throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
Um objeto `CFileTimeSpan` existente.

*nSpan*\
Um período de tempo em unidades FILETIME.

### <a name="remarks"></a>Comentários

O `CFileTimeSpan` objeto pode ser criado `CFileTimeSpan` usando um objeto existente ou expresso como um valor de 64 bits em unidades FILETIME de 100 nanossegundos. Para obter mais informações, consulte [CFileTime](cfiletime-class.md). O construtor padrão define o intervalo de tempo para 0.

## <a name="cfiletimespangettimespan"></a><a name="gettimespan"></a>CFileTimeSpan::getTimespan

Chame este método para recuperar `CFileTimeSpan` o tempo do objeto.

```cpp
LONGLONG GetTimeSpan() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o intervalo de tempo em unidades FILETIME de 100 nanossegundos. Para obter mais informações, consulte [CFileTime](cfiletime-class.md).

## <a name="cfiletimespanoperator--"></a><a name="operator_-"></a>CFileTimeSpan::operador -

Executa subtração `CFileTimeSpan` em um objeto.

```cpp
CFileTimeSpan operator-(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
Um objeto `CFileTimeSpan` .

### <a name="return-value"></a>Valor retornado

Retorna `CFileTimeSpan` um objeto representando o resultado da diferença entre dois períodos de tempo.

## <a name="cfiletimespanoperator-"></a><a name="operator_neq"></a>CFileTimeSpan::operador !=

Compara dois objetos `CFileTimeSpan` quanto à desigualdade.

```cpp
bool operator!=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o item a ser `CFileTimeSpan` comparado não for igual ao objeto; caso contrário, FALSO.

## <a name="cfiletimespanoperator-"></a><a name="operator_add"></a>CFileTimeSpan::operador +

Executa a `CFileTimeSpan` adição em um objeto.

```cpp
CFileTimeSpan operator+(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
Um objeto `CFileTimeSpan` .

### <a name="return-value"></a>Valor retornado

Retorna `CFileTimeSpan` um objeto contendo a soma dos dois períodos de tempo.

## <a name="cfiletimespanoperator-"></a><a name="operator_add_eq"></a>CFileTimeSpan::operador +=

Executa a `CFileTimeSpan` adição em um objeto e atribui o resultado ao objeto atual.

```cpp
CFileTimeSpan& operator+=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
Um objeto `CFileTimeSpan` .

### <a name="return-value"></a>Valor retornado

Retorna o `CFileTimeSpan` objeto atualizado contendo a soma dos dois períodos de tempo.

## <a name="cfiletimespanoperator-lt"></a><a name="operator_lt"></a>CFileTimeSpan::operador&lt;

Compara `CFileTimeSpan` dois objetos para determinar o menor.

```cpp
bool operator<(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for menor (ou seja, representa um período de tempo mais curto) do que o segundo, caso contrário, FALSO.

## <a name="cfiletimespanoperator-lt"></a><a name="operator_lt_eq"></a>CFileTimeSpan::operador&lt;=

Compara `CFileTimeSpan` dois objetos para determinar a igualdade ou o menor.

```cpp
bool operator<=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for menor do que (ou seja, representa um período de tempo mais curto) ou igual ao segundo, caso contrário, FALSO.

## <a name="cfiletimespanoperator-"></a><a name="operator_eq"></a>CFileTimeSpan::operador =

O operador de atribuição.

```cpp
CFileTimeSpan& operator=(const CFileTimeSpan& span) throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
Um objeto `CFileTimeSpan` .

### <a name="return-value"></a>Valor retornado

Retorna o `CFileTimeSpan` objeto atualizado.

## <a name="cfiletimespanoperator--"></a><a name="operator_-_eq"></a>CFileTimeSpan::operador -=

Executa subtração `CFileTimeSpan` em um objeto e atribui o resultado ao objeto atual.

```cpp
CFileTimeSpan& operator-=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
Um objeto `CFileTimeSpan` .

### <a name="return-value"></a>Valor retornado

Retorna o `CFileTimeSpan` objeto atualizado.

## <a name="cfiletimespanoperator-"></a><a name="operator_eq_eq"></a>CFileTimeSpan::operador ==

Compara dois objetos `CFileTimeSpan` quanto à igualdade.

```cpp
bool operator==(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se os objetos forem iguais, caso contrário, FALSO.

## <a name="cfiletimespanoperator-gt"></a><a name="operator_gt"></a>CFileTimeSpan::operador&gt;

Compara `CFileTimeSpan` dois objetos para determinar o maior.

```cpp
bool operator>(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for maior do que (ou seja, representa um período de tempo mais longo) do que o segundo, caso contrário, FALSO.

## <a name="cfiletimespanoperator-gt"></a><a name="operator_gt_eq"></a>CFileTimeSpan::operador&gt;=

Compara `CFileTimeSpan` dois objetos para determinar a igualdade ou o maior.

```cpp
bool operator>=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*\
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for maior do que (ou seja, representa um período de tempo mais longo) ou igual ao segundo, caso contrário, FALSO.

## <a name="cfiletimespansettimespan"></a><a name="settimespan"></a>CFileTimeSpan::setTimeSpan

Chame este método para definir `CFileTimeSpan` o período de tempo do objeto.

```cpp
void SetTimeSpan(LONGLONG nSpan) throw();
```

### <a name="parameters"></a>Parâmetros

*nSpan*\
O novo valor para o período de tempo em unidades FILETIME de 100 nanossegundos. Para obter mais informações, consulte [CFileTime](cfiletime-class.md).

## <a name="see-also"></a>Confira também

[Filetime](/windows/win32/api/minwinbase/ns-minwinbase-filetime)\
[Classe CFileTime](cfiletime-class.md)\
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)\
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
