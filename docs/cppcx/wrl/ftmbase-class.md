---
title: Classe FtmBase
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase
- ftm/Microsoft::WRL::FtmBaseCreateGlobalInterfaceTable
- ftm/Microsoft::WRL::FtmBase::DisconnectObject
- ftm/Microsoft::WRL::FtmBase::FtmBase
- ftm/Microsoft::WRL::FtmBase::GetMarshalSizeMax
- ftm/Microsoft::WRL::FtmBase::GetUnmarshalClass
- ftm/Microsoft::WRL::FtmBase::MarshalInterface
- ftm/Microsoft::WRL::FtmBase::marshaller_
- ftm/Microsoft::WRL::FtmBase::ReleaseMarshalData
- ftm/Microsoft::WRL::FtmBase::UnmarshalInterface
helpviewer_keywords:
- Microsoft::WRL::FtmBase class
- Microsoft::WRL::FtmBase::CreateGlobalInterfaceTable method
- Microsoft::WRL::FtmBase::DisconnectObject method
- Microsoft::WRL::FtmBase::FtmBase, constructor
- Microsoft::WRL::FtmBase::GetMarshalSizeMax method
- Microsoft::WRL::FtmBase::GetUnmarshalClass method
- Microsoft::WRL::FtmBase::MarshalInterface method
- Microsoft::WRL::FtmBase::marshaller_ data member
- Microsoft::WRL::FtmBase::ReleaseMarshalData method
- Microsoft::WRL::FtmBase::UnmarshalInterface method
ms.assetid: 275f3b71-2975-4f92-89e7-d351e96496df
ms.openlocfilehash: f28a850c365bc9a75d8e5b100e5e5cc0a1c5dc10
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404558"
---
# <a name="ftmbase-class"></a>Classe FtmBase

Representa um objeto de marshaling com thread livre.

## <a name="syntax"></a>Sintaxe

```cpp
class FtmBase :
    public Microsoft::WRL::Implements<
        Microsoft::WRL::RuntimeClassFlags<WinRtClassicComMix>,
        Microsoft::WRL::CloakedIid<IMarshal>
    >;
```

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [classe RuntimeClass](runtimeclass-class.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

| Nome                         | Descrição                                        |
| ---------------------------- | -------------------------------------------------- |
| [FtmBase::FtmBase](#ftmbase) | Inicializa uma nova instância da classe `FtmBase`. |

### <a name="public-methods"></a>Métodos públicos

| Nome                                                               | Descrição                                                                                                                                                          |
| ------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [FtmBase::CreateGlobalInterfaceTable](#createglobalinterfacetable) | Cria uma tabela de interface global (GIT).                                                                                                                              |
| [FtmBase::D isconnectobject](#disconnectobject)                     | Libera forçosamente todas as conexões externas a um objeto. O servidor do objeto chama a implementação do objeto desse método antes de desligar.                |
| [FtmBase::GetMarshalSizeMax](#getmarshalsizemax)                   | Obtenha o limite superior do número de bytes necessários para realizar marshaling do ponteiro de interface especificado no objeto especificado.                                                |
| [FtmBase::GetUnmarshalClass](#getunmarshalclass)                   | Obtém o CLSID usado pelo COM para localizar a DLL que contém o código do proxy correspondente. COM carrega essa DLL para criar uma instância não inicializada do proxy. |
| [FtmBase::MarshalInterface](#marshalinterface)                     | Grava em um fluxo os dados necessários para inicializar um objeto proxy em algum processo cliente.                                                                          |
| [FtmBase::ReleaseMarshalData](#releasemarshaldata)                 | Destrói um pacote de dados com marshaling.                                                                                                                                    |
| [FtmBase::UnmarshalInterface](#unmarshalinterface)                 | Inicializa um proxy recém-criado e retorna um ponteiro de interface para esse proxy.                                                                                    |

### <a name="public-data-members"></a>Membros de Dados Públicos

| Nome                                | Descrição                                       |
| ----------------------------------- | ------------------------------------------------- |
| [FtmBase:: marshaller_](#marshaller) | Mantém uma referência ao marshaler livre de threads. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`FtmBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** FTM. h

**Namespace:** Microsoft:: WRL

## <a name="ftmbasecreateglobalinterfacetable"></a><a name="createglobalinterfacetable"></a>FtmBase::CreateGlobalInterfaceTable

Cria uma tabela de interface global (GIT).

```cpp
static HRESULT CreateGlobalInterfaceTable(
   __out IGlobalInterfaceTable **git
);
```

### <a name="parameters"></a>Parâmetros

*git*<br/>
Quando essa operação é concluída, um ponteiro para uma tabela de interface global.

### <a name="return-value"></a>Valor Retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [`IGlobalInterfaceTable`](https://docs.microsoft.com/windows/win32/api/objidl/nn-objidl-iglobalinterfacetable).

## <a name="ftmbasedisconnectobject"></a><a name="disconnectobject"></a>FtmBase::D isconnectobject

Libera forçosamente todas as conexões externas a um objeto. O servidor do objeto chama a implementação do objeto desse método antes de desligar.

```cpp
STDMETHODIMP DisconnectObject(
   __in DWORD dwReserved
) override;
```

### <a name="parameters"></a>Parâmetros

*dwReserved*<br/>
Reservado para uso futuro; deve ser zero.

### <a name="return-value"></a>Valor Retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="ftmbaseftmbase"></a><a name="ftmbase"></a>FtmBase::FtmBase

Inicializa uma nova instância da classe `FtmBase`.

```cpp
FtmBase();
```

## <a name="ftmbasegetmarshalsizemax"></a><a name="getmarshalsizemax"></a>FtmBase::GetMarshalSizeMax

Obtenha o limite superior do número de bytes necessários para realizar marshaling do ponteiro de interface especificado no objeto especificado.

```cpp
STDMETHODIMP GetMarshalSizeMax(
   __in REFIID riid,
   __in_opt void *pv,
   __in DWORD dwDestContext,
   __reserved void *pvDestContext,
   __in DWORD mshlflags,
   __out DWORD *pSize
) override;
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Referência ao identificador da interface a ser empacotada.

*PV*<br/>
Ponteiro de interface a ser empacotado; pode ser NULL.

*dwDestContext*<br/>
Contexto de destino em que a interface especificada deve ser desempacotada.

Especifique um ou mais valores de enumeração MSHCTX.

Atualmente, o desempacotamento pode ocorrer em outro apartamento do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*<br/>
Reservado para uso futuro; deve ser NULL.

*mshlflags*<br/>
Sinalizador que indica se os dados a serem empacotados devem ser transmitidos de volta ao processo do cliente – o caso típico — ou gravados em uma tabela global, onde eles podem ser recuperados por vários clientes. Especifique um ou mais valores de enumeração MSHLFLAGS.

*pSize*<br/>
Quando essa operação for concluída, o ponteiro para o limite superior na quantidade de dados a ser gravado no fluxo de marshaling.

### <a name="return-value"></a>Valor Retornado

S_OK se for bem-sucedido; caso contrário, E_FAIL ou E_NOINTERFACE.

## <a name="ftmbasegetunmarshalclass"></a><a name="getunmarshalclass"></a>FtmBase::GetUnmarshalClass

Obtém o CLSID usado pelo COM para localizar a DLL que contém o código do proxy correspondente. COM carrega essa DLL para criar uma instância não inicializada do proxy.

```cpp
STDMETHODIMP GetUnmarshalClass(
   __in REFIID riid,
   __in_opt void *pv,
   __in DWORD dwDestContext,
   __reserved void *pvDestContext,
   __in DWORD mshlflags,
   __out CLSID *pCid
) override;
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Referência ao identificador da interface a ser empacotada.

*PV*<br/>
Ponteiro para a interface a ser empacotada; pode ser NULL se o chamador não tiver um ponteiro para a interface desejada.

*dwDestContext*<br/>
Contexto de destino em que a interface especificada deve ser desempacotada.

Especifique um ou mais valores de enumeração MSHCTX.

O desempacotamento pode ocorrer em outro apartamento do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*<br/>
Reservado para uso futuro; deve ser NULL.

*mshlflags*<br/>
Quando essa operação é concluída, o ponteiro para o CLSID a ser usado para criar um proxy no processo do cliente.

*pCid*

### <a name="return-value"></a>Valor Retornado

S_OK se for bem-sucedido; caso contrário, S_FALSE.

## <a name="ftmbasemarshalinterface"></a><a name="marshalinterface"></a>FtmBase::MarshalInterface

Grava em um fluxo os dados necessários para inicializar um objeto proxy em algum processo cliente.

```cpp
STDMETHODIMP MarshalInterface(
   __in IStream *pStm,
   __in REFIID riid,
   __in_opt void *pv,
   __in DWORD dwDestContext,
   __reserved void *pvDestContext,
   __in DWORD mshlflags
) override;
```

### <a name="parameters"></a>Parâmetros

*pStm*<br/>
Ponteiro para o fluxo a ser usado durante o marshaling.

*riid*<br/>
Referência ao identificador da interface a ser empacotada. Essa interface deve ser derivada da interface `IUnknown` .

*PV*<br/>
Ponteiro para o ponteiro de interface a ser empacotado; pode ser NULL se o chamador não tiver um ponteiro para a interface desejada.

*dwDestContext*<br/>
Contexto de destino em que a interface especificada deve ser desempacotada.

Especifique um ou mais valores de enumeração MSHCTX.

O desempacotamento pode ocorrer em outro apartamento do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*<br/>
Reservado para uso futuro; deve ser zero.

*mshlflags*<br/>
Especifica se os dados a serem empacotados devem ser transmitidos de volta ao processo do cliente – o caso típico — ou gravados em uma tabela global, onde eles podem ser recuperados por vários clientes.

### <a name="return-value"></a>Valor Retornado

S_OK o ponteiro de interface foi empacotado com êxito.

Não há suporte para E_NOINTERFACE a interface especificada.

STG_E_MEDIUMFULL o fluxo está cheio.

E_FAIL a operação falhou.

## <a name="ftmbasemarshaller_"></a><a name="marshaller"></a>FtmBase:: marshaller_

Mantém uma referência ao marshaler livre de threads.

```cpp
Microsoft::WRL::ComPtr<IMarshal> marshaller_; ;
```

## <a name="ftmbasereleasemarshaldata"></a><a name="releasemarshaldata"></a>FtmBase::ReleaseMarshalData

Destrói um pacote de dados com marshaling.

```cpp
STDMETHODIMP ReleaseMarshalData(
   __in IStream *pStm
) override;
```

### <a name="parameters"></a>Parâmetros

*pStm*<br/>
Ponteiro para um fluxo que contém o pacote de dados a ser destruído.

### <a name="return-value"></a>Valor Retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="ftmbaseunmarshalinterface"></a><a name="unmarshalinterface"></a>FtmBase::UnmarshalInterface

Inicializa um proxy recém-criado e retorna um ponteiro de interface para esse proxy.

```cpp
STDMETHODIMP UnmarshalInterface(
   __in IStream *pStm,
   __in REFIID riid,
   __deref_out void **ppv
) override;
```

### <a name="parameters"></a>Parâmetros

*pStm*<br/>
Ponteiro para o fluxo do qual o ponteiro de interface deve ser desempacotado.

*riid*<br/>
Referência ao identificador da interface a ser desempacotada.

*ppv*<br/>
Quando essa operação é concluída, o endereço de uma variável de ponteiro que recebe o ponteiro de interface solicitado em *riid*. Se essa operação for bem-sucedida, **PPV* conterá o ponteiro de interface solicitado da interface a ser desempacotado.

### <a name="return-value"></a>Valor Retornado

S_OK se for bem-sucedido; caso contrário, E_NOINTERFACE ou E_FAIL.
