---
title: Tipo de conversão de objetos de classe MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.classes
dev_langs:
- C++
helpviewer_keywords:
- macros [MFC], type casting
- pointers [MFC], type casting
- type casts [MFC]
- casting types [MFC]
- macros [MFC], casting pointers
ms.assetid: e138465e-c35f-4e84-b788-bd200ccf2f0e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 217be53a78a65a0f617438127b922b20c950853d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33371153"
---
# <a name="type-casting-of-mfc-class-objects"></a>Conversão de tipo de objetos de classe MFC
Macros de conversão de tipo fornecem uma maneira de converter um determinado ponteiro para um ponteiro que aponta para um objeto de classe específica, com ou sem verificar se a conversão é legal.  
  
 A tabela a seguir lista as macros de conversão de tipo do MFC.  
  
### <a name="macros-that-cast-pointers-to-mfc-class-objects"></a>Macros que converter ponteiros para objetos de classe MFC  
  
|||  
|-|-|  
|[DYNAMIC_DOWNCAST](#dynamic_downcast)|Converte um ponteiro para um ponteiro para um objeto de classe ao verificar se a conversão é legal.|  
|[STATIC_DOWNCAST](#static_downcast)|Converte um ponteiro para um objeto de uma classe para um ponteiro de um tipo relacionado. Em uma compilação de depuração, faz com que um **ASSERT** se o objeto não é um "tipo de" o tipo de destino.|  
  
##  <a name="dynamic_downcast"></a>  DYNAMIC_DOWNCAST  
 Fornece uma maneira útil de converter um ponteiro para um ponteiro para um objeto de classe ao verificar se a conversão é legal.  
  
```   
DYNAMIC_DOWNCAST(class, pointer)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `class`  
 O nome de uma classe.  
  
 `pointer`  
 Um ponteiro para ser convertido em um ponteiro para um objeto do tipo `class`.  
  
### <a name="remarks"></a>Comentários  
 A macro será convertido a `pointer` um ponteiro para um objeto de parâmetro a `class` tipo do parâmetro.  
  
 Se o objeto referenciado pelo ponteiro é um "tipo de" classe identificado, a macro retorna o ponteiro apropriado. Se não for uma conversão legal, a macro retorna **nulo**.  
  
##  <a name="static_downcast"></a>  STATIC_DOWNCAST  
 Conversões *pobject* para um ponteiro para um *class_name* objeto.  
  
```   
STATIC_DOWNCAST(class_name, pobject)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe que está sendo convertido em.  
  
 *pobject*  
 O ponteiro para ser convertido em um ponteiro para um *class_name* objeto.  
  
### <a name="remarks"></a>Comentários  
 *pobject* devem ser **nulo**, ou apontar para um objeto de uma classe que deriva diretamente ou indiretamente, de *class_name*. Em compilações de seu aplicativo com o **Debug** símbolo do pré-processador definido, a macro será **ASSERT** se *pobject* não é **nulo**, ou Se ele aponta para um objeto que não é um "tipo de" da classe especificada no *class_name* parâmetro (consulte [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof)). Não- **Debug** compilações, a macro executa a conversão sem nenhuma verificação de tipo.  
  
 A classe especificada no *class_name* parâmetro deve ser derivado de `CObject` e deve usar o `DECLARE_DYNAMIC` e `IMPLEMENT_DYNAMIC`, o `DECLARE_DYNCREATE` e `IMPLEMENT_DYNCREATE`, ou o `DECLARE_SERIAL` e `IMPLEMENT_SERIAL`macros conforme explicado no artigo [classe CObject: derivando uma classe de CObject](../../mfc/deriving-a-class-from-cobject.md).  
  
 Por exemplo, você pode converter um ponteiro para `CMyDoc`, chamado `pMyDoc`, com um ponteiro para **CDocument** usando esta expressão:  
  
 [!code-cpp[NVC_MFCDocView#197](../../mfc/codesnippet/cpp/type-casting-of-mfc-class-objects_1.cpp)]  
  
 Se `pMyDoc` não aponta para um objeto derivado direta ou indiretamente de **CDocument**, a macro será **ASSERT**.  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
