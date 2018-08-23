---
title: 'Método ftmbase:: Getunmarshalclass | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase::GetUnmarshalClass
dev_langs:
- C++
helpviewer_keywords:
- GetUnmarshalClass method
ms.assetid: 535fc539-5b97-4967-b158-f7568f13d341
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c76c2d75f3d8c2e872b29d9ecf07841c99027713
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42599497"
---
# <a name="ftmbasegetunmarshalclass-method"></a>Método FtmBase::GetUnmarshalClass

Obtém o CLSID que COM usa para localizar a DLL que contém o código para o proxy correspondente. COM carrega essa DLL para criar uma instância não inicializada do proxy.

## <a name="syntax"></a>Sintaxe

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

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, S_FALSE.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ftm.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe FtmBase](../windows/ftmbase-class.md)