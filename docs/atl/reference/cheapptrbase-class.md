---
title: Classe CHeapptrBase
ms.date: 11/04/2016
f1_keywords:
- CHeapPtrBase
- ATLCORE/ATL::CHeapPtrBase
- ATLCORE/ATL::CHeapPtrBase::AllocateBytes
- ATLCORE/ATL::CHeapPtrBase::Attach
- ATLCORE/ATL::CHeapPtrBase::Detach
- ATLCORE/ATL::CHeapPtrBase::Free
- ATLCORE/ATL::CHeapPtrBase::ReallocateBytes
- ATLCORE/ATL::CHeapPtrBase::m_pData
helpviewer_keywords:
- CHeapPtrBase class
ms.assetid: 501ac1b2-fb34-4c72-b7e6-a4f1fc8fda21
ms.openlocfilehash: 62cabf281473cdf21fe260fa23082bc55f339849
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326898"
---
# <a name="cheapptrbase-class"></a>Classe CHeapptrBase

Esta classe forma a base para várias classes inteligentes de ponteiro sinuoso.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, class Allocator = CCRTAllocator>
class CHeapPtrBase
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de objeto a ser armazenado no heap.

*Alocador*<br/>
A classe de alocação de memória para usar. Por padrão, as rotinas de CRT são usadas para alocar e liberar a memória.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtrBase::~CHeapPtrBase](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtrBase::AllocateBytes](#allocatebytes)|Chame este método para alocar memória.|
|[CHeapPtrBase::Anexar](#attach)|Chame este método para tomar posse de um ponteiro existente.|
|[CHeapPtrBase::Detach](#detach)|Chame este método para liberar a propriedade de um ponteiro.|
|[CHeapPtrBase::Grátis](#free)|Chame este método para excluir um `CHeapPtrBase`objeto apontado por um .|
|[CHeapPtrBase::RealocaçãoBytes](#reallocatebytes)|Chame este método para realocar a memória.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtrBase::operador T*](#operator_t_star)|O operador de elenco.|
|[CHeapPtrBase::&do operador](#operator_amp)|O operador &.|
|[CHeapPtrBase::operador ->](#operator_ptr)|O operador de ponteiro para membro.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeapPtrBase::m_pData](#m_pdata)|A variável membro de dados do ponteiro.|

## <a name="remarks"></a>Comentários

Esta classe forma a base para várias classes inteligentes de ponteiro sinuoso. As classes derivadas, por exemplo, [CHeapPtr](../../atl/reference/cheapptr-class.md) e [CComHeapPtr](../../atl/reference/ccomheapptr-class.md), adicionam seus próprios construtores e operadores. Consulte essas classes para exemplos de implementação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="cheapptrbaseallocatebytes"></a><a name="allocatebytes"></a>CHeapPtrBase::AllocateBytes

Chame este método para alocar memória.

```
bool AllocateBytes(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
O número de bytes de memória para alocar.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a memória for alocada com sucesso, falsa de outra forma.

### <a name="remarks"></a>Comentários

Em compilações de depuração, uma falha de afirmação ocorrerá se a variável de membro [CHeapPtrBase::m_pData](#m_pdata) atualmente aponta para um valor existente; ou seja, não é igual a NULL.

## <a name="cheapptrbaseattach"></a><a name="attach"></a>CHeapPtrBase::Anexar

Chame este método para tomar posse de um ponteiro existente.

```
void Attach(T* pData) throw();
```

### <a name="parameters"></a>Parâmetros

*Pdata*<br/>
O `CHeapPtrBase` objeto tomará posse deste ponteiro.

### <a name="remarks"></a>Comentários

Quando `CHeapPtrBase` um objeto toma posse de um ponteiro, ele excluirá automaticamente o ponteiro e quaisquer dados alocados quando ele sair do escopo.

Em compilações de depuração, uma falha de afirmação ocorrerá se a variável de membro [CHeapPtrBase::m_pData](#m_pdata) atualmente aponta para um valor existente; ou seja, não é igual a NULL.

## <a name="cheapptrbasecheapptrbase"></a><a name="dtor"></a>CHeapPtrBase::~CHeapPtrBase

O destruidor.

```
~CHeapPtrBase() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="cheapptrbasedetach"></a><a name="detach"></a>CHeapPtrBase::Detach

Chame este método para liberar a propriedade de um ponteiro.

```
T* Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define a variável de membro [CHeapPtrBase::m_pData](#m_pdata) para NULL e retorna uma cópia do ponteiro.

## <a name="cheapptrbasefree"></a><a name="free"></a>CHeapPtrBase::Grátis

Chame este método para excluir um `CHeapPtrBase`objeto apontado por um .

```
void Free() throw();
```

### <a name="remarks"></a>Comentários

O objeto apontado `CHeapPtrBase` pelo é liberado e a variável de membro [CHeapPtrBase:m_pData](#m_pdata) está definida como NULL.

## <a name="cheapptrbasem_pdata"></a><a name="m_pdata"></a>CHeapPtrBase::m_pData

A variável membro de dados do ponteiro.

```
T* m_pData;
```

### <a name="remarks"></a>Comentários

Esta variável de membro contém as informações do ponteiro.

## <a name="cheapptrbaseoperator-amp"></a><a name="operator_amp"></a>CHeapPtrBase::operador&amp;

O operador &.

```
T** operator&() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o endereço do objeto `CHeapPtrBase` apontado pelo objeto.

## <a name="cheapptrbaseoperator--gt"></a><a name="operator_ptr"></a>CHeapPtrBase::operador -&gt;

O operador de ponteiro para membro.

```
T* operator->() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor da variável de membro [CHeapPtrBase::m_pData.](#m_pdata)

### <a name="remarks"></a>Comentários

Use este operador para chamar um método `CHeapPtrBase` em uma classe apontada pelo objeto. Nas compilações de depuração, uma `CHeapPtrBase` falha de afirmação ocorrerá se os pontos para NULL.

## <a name="cheapptrbaseoperator-t"></a><a name="operator_t_star"></a>CHeapPtrBase::operador T*

O operador de elenco.

```
operator T*() const throw();
```

### <a name="remarks"></a>Comentários

Retorna [CHeapPtrBase::m_pData](#m_pdata).

## <a name="cheapptrbasereallocatebytes"></a><a name="reallocatebytes"></a>CHeapPtrBase::RealocaçãoBytes

Chame este método para realocar a memória.

```
bool ReallocateBytes(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
A nova quantidade de memória para alocar, em bytes.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a memória for alocada com sucesso, falsa de outra forma.

## <a name="see-also"></a>Confira também

[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
