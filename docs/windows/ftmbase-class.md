---
title: Classe FtmBase | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-windows
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 687fd4f4bd77043bd0b74c7bcc39fb6a496b60be
ms.sourcegitcommit: 87d317ac62620c606464d860aaa9e375a91f4c99
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2018
ms.locfileid: "45601451"
---
# <a name="ftmbase-class"></a>Classe FtmBase

Representa um objeto livre de marshaler.

## <a name="syntax"></a>Sintaxe

```cpp
class FtmBase : public Microsoft::WRL::Implements<
   Microsoft::WRL::RuntimeClassFlags<WinRtClassicComMix>,
   Microsoft::WRL::CloakedIid<IMarshal> >;
```

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [classe RuntimeClass](runtimeclass-class.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

| Nome                         | Descrição                                        |
| ---------------------------- | -------------------------------------------------- |
| [Ftmbase:: Ftmbase](#ftmbase) | Inicializa uma nova instância da classe `FtmBase`. |

### <a name="public-methods"></a>Métodos públicos

| Nome                                                               | Descrição                                                                                                                                                          |
| ------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [Ftmbase:: Createglobalinterfacetable](#createglobalinterfacetable) | Cria uma tabela de interface global (GIT).                                                                                                                              |
| [Ftmbase:: Disconnectobject](#disconnectobject)                     | Libera forçadamente todas as conexões externas para um objeto. Servidor do objeto chama a implementação do objeto desse método antes de desligar.                |
| [Ftmbase:: Getmarshalsizemax](#getmarshalsizemax)                   | Obtenha o limite superior no número de bytes necessários para realizar marshaling do ponteiro de interface especificado no objeto especificado.                                                |
| [Ftmbase:: Getunmarshalclass](#getunmarshalclass)                   | Obtém o CLSID que COM usa para localizar a DLL que contém o código para o proxy correspondente. COM carrega essa DLL para criar uma instância não inicializada do proxy. |
| [Ftmbase:: Marshalinterface](#marshalinterface)                     | Grava os dados necessários para inicializar um objeto de proxy em algum processo do cliente em um fluxo.                                                                          |
| [Ftmbase:: Releasemarshaldata](#releasemarshaldata)                 | Destrói um pacote de dados com marshaling.                                                                                                                                    |
| [Ftmbase:: Unmarshalinterface](#unmarshalinterface)                 | Inicializa um proxy recém-criado e retorna um ponteiro de interface para esse proxy.                                                                                    |

### <a name="public-data-members"></a>Membros de Dados Públicos

| Nome                                | Descrição                                       |
| ----------------------------------- | ------------------------------------------------- |
| [FtmBase::marshaller_](#marshaller) | Contém uma referência para o marshaler livre. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`FtmBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ftm.h

**Namespace:** Microsoft::WRL

## <a name="createglobalinterfacetable"></a>Ftmbase:: Createglobalinterfacetable

Cria uma tabela de interface global (GIT).

```cpp
static HRESULT CreateGlobalInterfaceTable(
   __out IGlobalInterfaceTable **git
);
```

### <a name="parameters"></a>Parâmetros

*Git*  
Quando essa operação for concluída, um ponteiro para uma tabela de interface global.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o `IGlobalInterfaceTable` tópico na `COM Interfaces` subtópico o `COM Reference` tópico na biblioteca MSDN.

## <a name="disconnectobject"></a>Ftmbase:: Disconnectobject

Libera forçadamente todas as conexões externas para um objeto. Servidor do objeto chama a implementação do objeto desse método antes de desligar.

```cpp
STDMETHODIMP DisconnectObject(
   __in DWORD dwReserved
) override;
```

### <a name="parameters"></a>Parâmetros

*dwReserved*  
Reservado para uso futuro; deve ser zero.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="ftmbase"></a>Ftmbase:: Ftmbase

Inicializa uma nova instância da classe `FtmBase`.

```cpp
FtmBase();
```

## <a name="getmarshalsizemax"></a>Ftmbase:: Getmarshalsizemax

Obtenha o limite superior no número de bytes necessários para realizar marshaling do ponteiro de interface especificado no objeto especificado.

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

*riid*  
Referência ao identificador da interface a ser empacotado.

*VP*  
Ponteiro de interface para ser empacotado; pode ser NULL.

*dwDestContext*  
Contexto de destino onde a interface especificada deve ser desempacotada.

Especifique um ou mais valores de enumeração MSHCTX.

Atualmente, o unmarshaling pode ocorrer em outra apartment do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*  
Reservado para uso futuro; deve ser NULL.

*mshlflags*  
Sinalizador que indica se os dados a ser empacotado deve ser transmitido de volta para o processo do cliente — o caso comum — ou gravados em uma tabela global, onde ela pode ser recuperada por vários clientes. Especifique um ou mais valores de enumeração MSHLFLAGS.

*pSize*  
Quando essa operação for concluída, ponteiro para o limite superior na quantidade de dados a serem gravados no fluxo de marshaling.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_FAIL ou E_NOINTERFACE.

## <a name="getunmarshalclass"></a>Ftmbase:: Getunmarshalclass

Obtém o CLSID que COM usa para localizar a DLL que contém o código para o proxy correspondente. COM carrega essa DLL para criar uma instância não inicializada do proxy.

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

*riid*  
Referência ao identificador da interface a ser empacotado.

*VP*  
Ponteiro para a interface a ser empacotado; pode ser NULL se o chamador não tem um ponteiro para a interface desejada.

*dwDestContext*  
Contexto de destino onde a interface especificada deve ser desempacotada.

Especifique um ou mais valores de enumeração MSHCTX.

Unmarshaling pode ocorrer em outra apartment do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*  
Reservado para uso futuro; deve ser NULL.

*mshlflags*  
Quando essa operação for concluída, ponteiro para o CLSID para ser usado para criar um proxy no processo de cliente.

*pCid*

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, S_FALSE.

## <a name="marshalinterface"></a>Ftmbase:: Marshalinterface

Grava os dados necessários para inicializar um objeto de proxy em algum processo do cliente em um fluxo.

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

*pStm*  
Ponteiro para o fluxo a ser usado durante o marshaling.

*riid*  
Referência ao identificador da interface a ser empacotado. Essa interface deve ser derivada de `IUnknown` interface.

*VP*  
Ponteiro para o ponteiro de interface para ser empacotado; pode ser NULL se o chamador não tem um ponteiro para a interface desejada.

*dwDestContext*  
Contexto de destino onde a interface especificada deve ser desempacotada.

Especifique um ou mais valores de enumeração MSHCTX.

Unmarshaling pode ocorrer em outra apartment do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).

*pvDestContext*  
Reservado para uso futuro; deve ser zero.

*mshlflags*  
Especifica se os dados a ser empacotado deve ser transmitido de volta para o processo do cliente — o caso comum — ou gravados em uma tabela global, onde ela pode ser recuperada por vários clientes.

### <a name="return-value"></a>Valor de retorno

S_OK o ponteiro de interface foi empacotado com êxito.

Não há suporte para a interface especificada de E_NOINTERFACE.

STG_E_MEDIUMFULL o fluxo está cheio.

E_FAIL a operação falha.

## <a name="marshaller"></a>FtmBase::marshaller_

Contém uma referência para o marshaler livre.

```cpp
Microsoft::WRL::ComPtr<IMarshal> marshaller_; ;
```

## <a name="releasemarshaldata"></a>Ftmbase:: Releasemarshaldata

Destrói um pacote de dados com marshaling.

```cpp
STDMETHODIMP ReleaseMarshalData(
   __in IStream *pStm
) override;
```

### <a name="parameters"></a>Parâmetros

*pStm*  
Ponteiro para um fluxo que contém o pacote de dados a ser destruído.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="unmarshalinterface"></a>Ftmbase:: Unmarshalinterface

Inicializa um proxy recém-criado e retorna um ponteiro de interface para esse proxy.

```cpp
STDMETHODIMP UnmarshalInterface(
   __in IStream *pStm,
   __in REFIID riid,
   __deref_out void **ppv
) override;
```

### <a name="parameters"></a>Parâmetros

*pStm*  
Ponteiro para o fluxo do qual o ponteiro de interface deve ser desempacotada.

*riid*  
Referência ao identificador da interface a ser desempacotada.

*ppv*  
Quando essa operação for concluída, o endereço de uma variável de ponteiro que recebe o ponteiro de interface solicitado no *riid*. Se essa operação for bem-sucedida, **ppv* contém o ponteiro da interface a ser desempacotada de interface solicitada.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_FAIL ou E_NOINTERFACE.
