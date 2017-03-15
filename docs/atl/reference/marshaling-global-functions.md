---
title: "Funções globais de empacotamento | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 877100b5-6ad9-44c5-a2e0-09414f1720d0
caps.latest.revision: 19
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
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: dd4b8d50ec69974b7b2af29438b1657e1ce592b4
ms.lasthandoff: 02/25/2017

---
# <a name="marshaling-global-functions"></a>Empacotamento de funções globais
Essas funções fornecem suporte para empacotamento e a conversão de dados de marshaling em ponteiros de interface.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlFreeMarshalStream](#atlfreemarshalstream)|Libera o marshaling de dados e o `IStream` ponteiro.|  
|[AtlMarshalPtrInProc](#atlmarshalptrinproc)|Cria um novo objeto de fluxo e empacota o ponteiro de interface especificado.|  
|[AtlUnmarshalPtr](#atlunmarshalptr)|Converte dados de empacotamento do fluxo em um ponteiro de interface.|  
  
##  <a name="a-nameatlfreemarshalstreama--atlfreemarshalstream"></a><a name="atlfreemarshalstream"></a>AtlFreeMarshalStream  
 Libera os dados de marshaling no fluxo e depois libera o ponteiro de fluxo.  

```
HRESULT AtlFreeMarshalStream(IStream* pStream);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 [in] Um ponteiro para o `IStream` interface no fluxo usado para marshaling.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [AtlMarshalPtrInProc](#atlmarshalptrinproc).  
  
##  <a name="a-nameatlmarshalptrinproca--atlmarshalptrinproc"></a><a name="atlmarshalptrinproc"></a>AtlMarshalPtrInProc  
 Cria um novo objeto de fluxo, grava o CLSID do proxy no fluxo e realiza o marshaling do ponteiro de interface especificado gravando os dados necessários para inicializar o proxy no fluxo.  
  
```
HRESULT AtlMarshalPtrInProc(
    IUnknown* pUnk,
    const IID& iid,
    IStream** ppStream);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] Um ponteiro para a interface para ser empacotado.  
  
 `iid`  
 [in] O GUID da interface que está sendo empacotado.  
  
 `ppStream`  
 [out] Um ponteiro para o `IStream` interface no novo objeto de fluxo usado para marshaling.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 O **MSHLFLAGS_TABLESTRONG** sinalizador é definido para o ponteiro pode ser empacotado para vários fluxos. O ponteiro pode também ser desempacotado várias vezes.  
  
 Se o marshaling falhar, o ponteiro de fluxo é liberado.  
  
 `AtlMarshalPtrInProc`só pode ser usada em um ponteiro para um objeto no processo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&#50;](../../atl/codesnippet/cpp/marshaling-global-functions_1.cpp)]  
  
##  <a name="a-nameatlunmarshalptra--atlunmarshalptr"></a><a name="atlunmarshalptr"></a>AtlUnmarshalPtr  
 Converte os dados de marshaling do fluxo em um ponteiro de interface que pode ser usado pelo cliente.  
   
```
HRESULT AtlUnmarshalPtr(
    IStream* pStream,
    const IID& iid,
    IUnknown** ppUnk);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 [in] Um ponteiro para o fluxo que está sendo desempacotado.  
  
 `iid`  
 [in] O GUID da interface sendo desempacotada.  
  
 `ppUnk`  
 [out] Um ponteiro para a interface desempacotada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [AtlMarshalPtrInProc](#atlmarshalptrinproc).  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

