---
title: Conversão de tipo de objetos de classe MFC
ms.date: 11/04/2016
helpviewer_keywords:
- macros [MFC], type casting
- pointers [MFC], type casting
- type casts [MFC]
- casting types [MFC]
- macros [MFC], casting pointers
ms.assetid: e138465e-c35f-4e84-b788-bd200ccf2f0e
ms.openlocfilehash: c7586f3c3f3aefd78fa868cc847df27e8aac58ab
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611653"
---
# <a name="type-casting-of-mfc-class-objects"></a>Conversão de tipo de objetos de classe MFC

Macros de conversão de tipo fornecem uma maneira de converter um ponteiro especificado para um ponteiro que aponta para um objeto de classe específica, com ou sem verificar se a conversão é legal.

A tabela a seguir lista as macros de conversão de tipo do MFC.

### <a name="macros-that-cast-pointers-to-mfc-class-objects"></a>Macros que converter ponteiros para objetos de classe MFC

|||
|-|-|
|[DYNAMIC_DOWNCAST](#dynamic_downcast)|Converte um ponteiro para um ponteiro para um objeto da classe durante a verificação para ver se a conversão é legal.|
|[STATIC_DOWNCAST](#static_downcast)|Converte um ponteiro para um objeto de uma classe em um ponteiro de um tipo relacionado. Em uma compilação de depuração faz com que uma declaração se o objeto não é um "tipo de" o tipo de destino.|

##  <a name="dynamic_downcast"></a>  DYNAMIC_DOWNCAST

Fornece uma maneira útil para converter um ponteiro para um ponteiro para um objeto da classe durante a verificação para ver se a conversão é legal.

```
DYNAMIC_DOWNCAST(class, pointer)
```

### <a name="parameters"></a>Parâmetros

*class*<br/>
O nome de uma classe.

*pointer*<br/>
Um ponteiro para ser convertido em um ponteiro para um objeto do tipo *classe*.

### <a name="remarks"></a>Comentários

A macro será convertido a *ponteiro* parâmetro em um ponteiro para um objeto do *classe* tipo do parâmetro.

Se o objeto referenciado pelo ponteiro é um "tipo de" classe identificado, a macro retorna o ponteiro apropriado. Se não for uma conversão legal, a macro retorna NULL.

##  <a name="static_downcast"></a>  STATIC_DOWNCAST

Conversões *pobject* em um ponteiro para um *class_name* objeto.

```
STATIC_DOWNCAST(class_name, pobject)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe que está sendo convertido.

*pobject*<br/>
O ponteiro a ser convertido em um ponteiro para um *class_name* objeto.

### <a name="remarks"></a>Comentários

*pobject* deve ser NULL ou apontar para um objeto de uma classe que deriva diretamente ou indiretamente, de *class_name*. Em compilações do seu aplicativo com o símbolo do pré-processador debug definido, a macro DECLARARÁ se *pobject* não for nulo, ou se ele apontar para um objeto que não é um "tipo de" da classe especificada no *class_name*parâmetro (consulte [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof)). Em não - **Debug** compilações, a macro executa a conversão sem nenhuma verificação de tipo.

A classe especificada na *class_name* parâmetro deve ser derivado de `CObject` e deve usar o DECLARE_DYNAMIC e IMPLEMENT_DYNAMIC, o DECLARE_DYNCREATE e IMPLEMENT_DYNCREATE, ou o DECLARE_SERIAL e IMPLEMENT_ Macros SERIAL como explicado no artigo [classe CObject: Derivando uma classe de CObject](../../mfc/deriving-a-class-from-cobject.md).

Por exemplo, você pode converter um ponteiro para `CMyDoc`, chamado `pMyDoc`, em um ponteiro para `CDocument` usando esta expressão:

[!code-cpp[NVC_MFCDocView#197](../../mfc/codesnippet/cpp/type-casting-of-mfc-class-objects_1.cpp)]

Se `pMyDoc` não aponta para um objeto derivado direta ou indiretamente de `CDocument`, DECLARARÁ a macro.

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
