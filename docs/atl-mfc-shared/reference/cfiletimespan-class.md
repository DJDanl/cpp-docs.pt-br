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
ms.openlocfilehash: 8d384ced5de588a348eb72b9852697694b370ee4
ms.sourcegitcommit: c85c8a1226d8fbbaa29f4691ed719f8e6cc6575c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2019
ms.locfileid: "54894153"
---
# <a name="cfiletimespan-class"></a>Classe CFileTimeSpan

Essa classe fornece métodos para gerenciamento de data relativa e valores de tempo associados com um arquivo.

## <a name="syntax"></a>Sintaxe

```
class CFileTimeSpan
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTimeSpan::CFileTimeSpan](#cfiletimespan)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTimeSpan::GetTimeSpan](#gettimespan)|Chame esse método para recuperar o período de tempo do `CFileTimeSpan` objeto.|
|[CFileTimeSpan::SetTimeSpan](#settimespan)|Chame esse método para definir o intervalo de tempo a `CFileTimeSpan` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTimeSpan::operator-](#operator_-)|Executa a subtração em um `CFileTimeSpan` objeto.|
|[CFileTimeSpan::operator !=](#operator_neq)|Compara dois objetos `CFileTimeSpan` quanto à desigualdade.|
|[CFileTimeSpan::operator +](#operator_add)|Executa a adição em um `CFileTimeSpan` objeto.|
|[CFileTimeSpan::operator +=](#operator_add_eq)|Executa a adição em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.|
|[CFileTimeSpan::operator &lt;](#operator_lt)|Compara dois `CFileTimeSpan` objetos para determinar o menor.|
|[CFileTimeSpan::operator &lt;=](#operator_lt_eq)|Compara dois `CFileTimeSpan` objetos para determinar igualdade ou o menor.|
|[CFileTimeSpan::operator =](#operator_eq)|O operador de atribuição.|
|[CFileTimeSpan::operator -=](#operator_-_eq)|Executa a subtração em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.|
|[CFileTimeSpan::operator ==](#operator_eq_eq)|Compara dois objetos `CFileTimeSpan` quanto à igualdade.|
|[CFileTimeSpan::operator &gt;](#operator_gt)|Compara dois `CFileTimeSpan` objetos para determinar o maior.|
|[CFileTimeSpan::operator &gt;=](#operator_gt_eq)|Compara dois `CFileTimeSpan` objetos para determinar igualdade ou maior.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para gerenciar relativos períodos de tempo costuma ser encontrado ao executar operações em relação a quando um arquivo foi criado, acessado pela última vez ou modificado pela última vez. Os métodos dessa classe são frequentemente usados em conjunto com [classe CFileTime](../../atl-mfc-shared/reference/cfiletime-class.md) objetos.

## <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](../../atl-mfc-shared/reference/cfiletime-class.md#millisecond).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime.h

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

O `CFileTimeSpan` objeto pode ser criado usando uma existente `CFileTimeSpan` de objeto ou expresso como um valor de 64 bits. O construtor padrão define o período de tempo como 0.

##  <a name="gettimespan"></a>  CFileTimeSpan::GetTimeSpan

Chame esse método para recuperar o período de tempo do `CFileTimeSpan` objeto.

```
LONGLONG GetTimeSpan() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o período de tempo em milissegundos.

##  <a name="operator_-"></a>  CFileTimeSpan::operator -

Executa a subtração em um `CFileTimeSpan` objeto.

```
CFileTimeSpan operator-(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTimeSpan` objeto que representa o resultado da diferença entre dois intervalos de tempo.

##  <a name="operator_neq"></a>  CFileTimeSpan::operator !=

Compara dois objetos `CFileTimeSpan` quanto à desigualdade.

```
bool operator!=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o item que está sendo comparado não for igual ao `CFileTimeSpan` objeto; caso contrário, FALSE.

##  <a name="operator_add"></a>  CFileTimeSpan::operator +

Executa a adição em um `CFileTimeSpan` objeto.

```
CFileTimeSpan operator+(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTimeSpan` do objeto que contém a soma do tempo de dois abrange.

##  <a name="operator_add_eq"></a>  CFileTimeSpan::operator +=

Executa a adição em um `CFileTimeSpan` do objeto e atribui o resultado ao objeto atual.

```
CFileTimeSpan& operator+=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CFileTimeSpan` do objeto que contém a soma do tempo de dois abrange.

##  <a name="operator_lt"></a>  CFileTimeSpan::operator &lt;

Compara dois `CFileTimeSpan` objetos para determinar o menor.

```
bool operator<(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o primeiro objeto é menor (ou seja, representa um período de tempo menor) que a segunda, caso contrário, FALSE.

##  <a name="operator_lt_eq"></a>  CFileTimeSpan::operator &lt;=

Compara dois `CFileTimeSpan` objetos para determinar igualdade ou o menor.

```
bool operator<=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o primeiro objeto é menor que (ou seja, representa um período de tempo menor) ou igual à segunda, caso contrário, FALSE.

##  <a name="operator_eq"></a>  CFileTimeSpan::operator =

O operador de atribuição.

```
CFileTimeSpan& operator=(const CFileTimeSpan& span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CFileTimeSpan` objeto.

##  <a name="operator_-_eq"></a>  CFileTimeSpan::operator -=

Executa a subtração em um `CFileTimeSpan` do objeto e atribui o resultado ao objeto atual.

```
CFileTimeSpan& operator-=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CFileTimeSpan` objeto.

##  <a name="operator_eq_eq"></a>  CFileTimeSpan::operator ==

Compara dois objetos `CFileTimeSpan` quanto à igualdade.

```
bool operator==(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se os objetos forem iguais, caso contrário, FALSE.

##  <a name="operator_gt"></a>  CFileTimeSpan::operator &gt;

Compara dois `CFileTimeSpan` objetos para determinar o maior.

```
bool operator>(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o primeiro objeto é maior que (ou seja, representa um período mais longo do tempo) que a segunda, caso contrário, FALSE.

##  <a name="operator_gt_eq"></a>  CFileTimeSpan::operator &gt;=

Compara dois `CFileTimeSpan` objetos para determinar igualdade ou maior.

```
bool operator>=(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
O objeto `CFileTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o primeiro objeto é maior que (ou seja, representa um período de tempo mais longo) ou igual à segunda, caso contrário, FALSE.

##  <a name="settimespan"></a>  CFileTimeSpan::SetTimeSpan

Chame esse método para definir o intervalo de tempo a `CFileTimeSpan` objeto.

```
void SetTimeSpan(LONGLONG nSpan) throw();
```

### <a name="parameters"></a>Parâmetros

*nSpan*<br/>
O novo valor para o período de tempo em milissegundos.

## <a name="see-also"></a>Consulte também

[FILETIME](/windows/desktop/api/minwinbase/ns-minwinbase-filetime)<br/>
[Classe CFileTime](../../atl-mfc-shared/reference/cfiletime-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
