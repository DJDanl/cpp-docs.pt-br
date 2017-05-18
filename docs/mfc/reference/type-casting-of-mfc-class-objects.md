---
title: "Tipo de conversão de objetos de classe MFC | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.classes
dev_langs:
- C++
helpviewer_keywords:
- macros, type casting
- pointers, type casting
- type casts
- casting types
- macros, casting pointers
ms.assetid: e138465e-c35f-4e84-b788-bd200ccf2f0e
caps.latest.revision: 15
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: f1ae094e7085017f03daab3f73323da13ab1be39
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="type-casting-of-mfc-class-objects"></a>Conversão de tipo de objetos de classe MFC
Macros de conversão de tipo fornecem uma maneira de converter um determinado ponteiro para um ponteiro aponta para um objeto de uma classe específica, com ou sem verificar se a conversão é legal.  
  
 A tabela a seguir lista as macros de conversão de tipo do MFC.  
  
### <a name="macros-that-cast-pointers-to-mfc-class-objects"></a>Macros que converter ponteiros para objetos de classe MFC  
  
|||  
|-|-|  
|[DYNAMIC_DOWNCAST](#dynamic_downcast)|Converte um ponteiro para um ponteiro para um objeto de classe ao verificar se a conversão é legal.|  
|[STATIC_DOWNCAST](#static_downcast)|Converte um ponteiro para um objeto de uma classe em um ponteiro de um tipo relacionado. Em uma compilação de depuração faz com que uma **ASSERT** se o objeto não é um "tipo de" o tipo de destino.|  
  
##  <a name="dynamic_downcast"></a>DYNAMIC_DOWNCAST  
 Fornece uma maneira útil para converter um ponteiro para um ponteiro para um objeto de classe ao verificar se a conversão é legal.  
  
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
  
##  <a name="static_downcast"></a>STATIC_DOWNCAST  
 Conversões *pobject* em um ponteiro para um *class_name* objeto.  
  
```   
STATIC_DOWNCAST(class_name, pobject)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe que está sendo convertido em.  
  
 *pobject*  
 O ponteiro para ser convertido em um ponteiro para um *class_name* objeto.  
  
### <a name="remarks"></a>Comentários  
 *pobject* deve ser **nulo**, ou apontar para um objeto de uma classe que é derivada diretamente ou indiretamente, de *class_name*. Em compilações do seu aplicativo com o **Debug** pré-processador símbolo definido, a macro será **ASSERT** se *pobject* não é **nulo**, ou se ele apontar para um objeto que não é um "tipo de" da classe especificada no *class_name* parâmetro (consulte [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof)). Em não - **Debug** compilações, a macro executa a conversão sem nenhuma verificação de tipo.  
  
 A classe especificada no *class_name* parâmetro deve ser derivado de `CObject` e deve usar o `DECLARE_DYNAMIC` e `IMPLEMENT_DYNAMIC`, o `DECLARE_DYNCREATE` e `IMPLEMENT_DYNCREATE`, ou `DECLARE_SERIAL` e `IMPLEMENT_SERIAL` macros conforme explicado no artigo [classe CObject: derivando uma classe de CObject](../../mfc/deriving-a-class-from-cobject.md).  
  
 Por exemplo, você pode converter um ponteiro para `CMyDoc`, chamado `pMyDoc`, em um ponteiro para **CDocument** usando esta expressão:  
  
 [!code-cpp[NVC_MFCDocView&#197;](../../mfc/codesnippet/cpp/type-casting-of-mfc-class-objects_1.cpp)]  
  
 Se `pMyDoc` não aponta para um objeto derivado direta ou indiretamente de **CDocument**, a macro será **ASSERT**.  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

