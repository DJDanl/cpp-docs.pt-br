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
ms.openlocfilehash: d37cdddda8cf8894016ed80b9055fe106b1600f7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371507"
---
# <a name="ftmbase-class"></a>Classe FtmBase

Representa um objeto marshaler de rosca livre.

## <a name="syntax"></a>Sintaxe

```cpp
class FtmBase :
    public Microsoft::WRL::Implements<
        Microsoft::WRL::RuntimeClassFlags<WinRtClassicComMix>,
        Microsoft::WRL::CloakedIid<IMarshal>
    >;
```

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [RuntimeClass .](runtimeclass-class.md)

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

| Nome                         | Descrição                                        |
| ---------------------------- | -------------------------------------------------- |
| [Base de ftm::FtmBase](#ftmbase) | Inicia uma nova instância da classe `FtmBase`. |

### <a name="public-methods"></a>Métodos públicos

| Nome                                                               | Descrição                                                                                                                                                          |
| ------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [FtmBase::CreateGlobalInterfaceTable](#createglobalinterfacetable) | Cria uma tabela de interface global (GIT).                                                                                                                              |
| [Base ftmBase::DisconnectObject](#disconnectobject)                     | Libera à força todas as conexões externas a um objeto. O servidor do objeto chama a implementação deste método antes de ser desligado.                |
| [Base de ftm::GetMarshalSizeMax](#getmarshalsizemax)                   | Obtenha o limite superior no número de bytes necessários para empacotar o ponteiro de interface especificado no objeto especificado.                                                |
| [FtmBase::GetUnmarshalClass](#getunmarshalclass)                   | Obtém o CLSID que o COM usa para localizar o DLL contendo o código para o proxy correspondente. O COM carrega essa DLL para criar uma instância não inicializada do proxy. |
| [FtmBase::MarshalInterface](#marshalinterface)                     | Grava em um fluxo os dados necessários para inicializar um objeto proxy em algum processo do cliente.                                                                          |
| [FtmBase::ReleaseMarshalData](#releasemarshaldata)                 | Destrói um pacote de dados empacotado.                                                                                                                                    |
| [FtmBase::UnmarshalInterface](#unmarshalinterface)                 | Inicializa um proxy recém-criado e retorna um ponteiro de interface para esse proxy.                                                                                    |

### <a name="public-data-members"></a>Membros de Dados Públicos

| Nome                                | Descrição                                       |
| ----------------------------------- | ------------------------------------------------- |
| [Base de ftm::marshaller_](#marshaller) | Tem uma referência ao marechal de rosca livre. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`FtmBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ftm.h

**Espaço de nome:** Microsoft::WRL

## <a name="ftmbasecreateglobalinterfacetable"></a><a name="createglobalinterfacetable"></a>FtmBase::CreateGlobalInterfaceTable

Cria uma tabela de interface global (GIT).

```cpp
static HRESULT CreateGlobalInterfaceTable(
   __out IGlobalInterfaceTable **git
);
```

### <a name="parameters"></a>Parâmetros

*Git*<br/>
Quando esta operação for concluída, um ponteiro para uma tabela de interface global.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Para obter mais `IGlobalInterfaceTable` informações, `COM Interfaces` consulte o `COM Reference` tópico no subtópico do tópico na Biblioteca MSDN.

## <a name="ftmbasedisconnectobject"></a><a name="disconnectobject"></a>Base ftmBase::DisconnectObject

Libera à força todas as conexões externas a um objeto. O servidor do objeto chama a implementação deste método antes de ser desligado.

```cpp
STDMETHODIMP DisconnectObject(
   __in DWORD dwReserved
) override;
```

### <a name="parameters"></a>Parâmetros

*dwReservado*<br/>
Reservado para uso futuro; deve ser zero.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="ftmbaseftmbase"></a><a name="ftmbase"></a>Base de ftm::FtmBase

Inicia uma nova instância da classe `FtmBase`.

```cpp
FtmBase();
```

## <a name="ftmbasegetmarshalsizemax"></a><a name="getmarshalsizemax"></a>Base de ftm::GetMarshalSizeMax

Obtenha o limite superior no número de bytes necessários para empacotar o ponteiro de interface especificado no objeto especificado.

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

*Pv*<br/>
Ponteiro de interface a ser empacotado; pode ser NULO.

*dwDestContext*<br/>
Contexto de destino onde a interface especificada deve ser desmarshaled.

Especifique um ou mais valores de enumeração MSHCTX.

Atualmente, o desmembramento pode ocorrer em outro apartamento do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*<br/>
Reservado para uso futuro; deve ser NULO.

*mshlflags*<br/>
Flagindicando se os dados a serem empacotados devem ser transmitidos de volta ao processo do cliente — o caso típico — ou gravados em uma tabela global, onde podem ser recuperados por vários clientes. Especifique um ou mais valores de enumeração MSHLFLAGS.

*Psize*<br/>
Quando esta operação for concluída, advirto o limite superior sobre a quantidade de dados a serem gravados no fluxo de marshaling.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; E_FAIL ou E_NOINTERFACE.

## <a name="ftmbasegetunmarshalclass"></a><a name="getunmarshalclass"></a>FtmBase::GetUnmarshalClass

Obtém o CLSID que o COM usa para localizar o DLL contendo o código para o proxy correspondente. O COM carrega essa DLL para criar uma instância não inicializada do proxy.

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

*Pv*<br/>
Ponteiro para a interface a ser empacotada; pode ser NULO se o chamador não tiver um ponteiro para a interface desejada.

*dwDestContext*<br/>
Contexto de destino onde a interface especificada deve ser desmarshaled.

Especifique um ou mais valores de enumeração MSHCTX.

O desempacotamento pode ocorrer em outro apartamento do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*<br/>
Reservado para uso futuro; deve ser NULO.

*mshlflags*<br/>
Quando esta operação for concluída, ponteiro para o CLSID para ser usado para criar um proxy no processo do cliente.

*pCid*

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, S_FALSE.

## <a name="ftmbasemarshalinterface"></a><a name="marshalinterface"></a>FtmBase::MarshalInterface

Grava em um fluxo os dados necessários para inicializar um objeto proxy em algum processo do cliente.

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

*Pv*<br/>
Ponteiro para o ponteiro de interface a ser empacotado; pode ser NULO se o chamador não tiver um ponteiro para a interface desejada.

*dwDestContext*<br/>
Contexto de destino onde a interface especificada deve ser desmarshaled.

Especifique um ou mais valores de enumeração MSHCTX.

O desmembramento pode ocorrer em outro apartamento do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*<br/>
Reservado para uso futuro; deve ser zero.

*mshlflags*<br/>
Especifica se os dados a serem empacotados devem ser transmitidos de volta ao processo do cliente — o caso típico — ou gravados em uma tabela global, onde podem ser recuperados por vários clientes.

### <a name="return-value"></a>Valor retornado

S_OK O ponteiro da interface foi empacotado com sucesso.

E_NOINTERFACE A interface especificada não é suportada.

STG_E_MEDIUMFULL o fluxo está cheio.

E_FAIL a operação falhou.

## <a name="ftmbasemarshaller_"></a><a name="marshaller"></a>Base de ftm::marshaller_

Tem uma referência ao marechal de rosca livre.

```cpp
Microsoft::WRL::ComPtr<IMarshal> marshaller_; ;
```

## <a name="ftmbasereleasemarshaldata"></a><a name="releasemarshaldata"></a>FtmBase::ReleaseMarshalData

Destrói um pacote de dados empacotado.

```cpp
STDMETHODIMP ReleaseMarshalData(
   __in IStream *pStm
) override;
```

### <a name="parameters"></a>Parâmetros

*pStm*<br/>
Ponteiro para um fluxo que contém o pacote de dados a ser destruído.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

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
Ponteiro para o fluxo a partir do qual o ponteiro de interface deve ser desmarshaled.

*riid*<br/>
Referência ao identificador da interface a ser desmembrada.

*Ppv*<br/>
Quando esta operação é concluída, o endereço de uma variável ponteiro que recebe o ponteiro de interface solicitado em *riid*. Se esta operação for bem sucedida, **ppv* contém o ponteiro de interface solicitado da interface a ser desmarshaled.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; E_NOINTERFACE ou E_FAIL.
