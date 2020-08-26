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
ms.openlocfilehash: e3702ced83021e42ac6bf71a78efc51fa07b8be9
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840486"
---
# <a name="type-casting-of-mfc-class-objects"></a>Conversão de tipo de objetos de classe MFC

As macros de conversão de tipo fornecem uma maneira de converter um ponteiro específico para um ponteiro que aponta para um objeto de classe específica, com ou sem verificar se a conversão é válida.

A tabela a seguir lista as macros de conversão de tipo MFC.

### <a name="macros-that-cast-pointers-to-mfc-class-objects"></a>Macros que convertem ponteiros para objetos de classe MFC

|Nome|Descrição|
|-|-|
|[DYNAMIC_DOWNCAST](#dynamic_downcast)|Converte um ponteiro para um ponteiro para um objeto de classe durante a verificação para ver se a conversão é válida.|
|[STATIC_DOWNCAST](#static_downcast)|Converte um ponteiro para um objeto de uma classe para um ponteiro de um tipo relacionado. Em uma compilação de depuração, o causará uma declaração se o objeto não for um "tipo" do tipo de destino.|

## <a name="dynamic_downcast"></a><a name="dynamic_downcast"></a> DYNAMIC_DOWNCAST

Fornece uma maneira prática de converter um ponteiro para um ponteiro para um objeto de classe durante a verificação para ver se a conversão é válida.

```
DYNAMIC_DOWNCAST(class, pointer)
```

### <a name="parameters"></a>parâmetros

*class*<br/>
O nome de uma classe.

*refere*<br/>
Um ponteiro a ser convertido em um ponteiro para um objeto do tipo *Class*.

### <a name="remarks"></a>Comentários

A macro converterá o parâmetro *pointer* em um ponteiro para um objeto do tipo do parâmetro de *classe* .

Se o objeto referenciado pelo ponteiro for um "tipo" da classe identificada, a macro retornará o ponteiro apropriado. Se não for uma conversão legal, a macro retornará NULL.

## <a name="static_downcast"></a><a name="static_downcast"></a> STATIC_DOWNCAST

Converte *pObject* em um ponteiro para um objeto *class_name* .

```
STATIC_DOWNCAST(class_name, pobject)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe que está sendo convertida.

*pobject*<br/>
O ponteiro a ser convertido em um ponteiro para um objeto *class_name* .

### <a name="remarks"></a>Comentários

*pObject* deve ser nulo ou apontar para um objeto de uma classe que é derivada diretamente, ou indiretamente, de *class_name*. Em compilações do seu aplicativo com o símbolo de pré-processador de _DEBUG definido, a macro será declarada se *pObject* não for NULL ou se apontará para um objeto que não seja um "tipo de" a classe especificada no parâmetro *Class_name* (consulte [CObject:: IsKindOf](../../mfc/reference/cobject-class.md#iskindof)). Em compilações não **_DEBUG** , a macro executa a conversão sem qualquer verificação de tipo.

A classe especificada no parâmetro *class_name* deve ser derivada de `CObject` e deve usar o DECLARE_DYNAMIC e IMPLEMENT_DYNAMIC, as DECLARE_DYNCREATE e IMPLEMENT_DYNCREATE ou as macros DECLARE_SERIAL e IMPLEMENT_SERIAL, conforme explicado no artigo [CObject Class: derivando uma classe de CObject](../../mfc/deriving-a-class-from-cobject.md).

Por exemplo, você pode converter um ponteiro para `CMyDoc` , chamado `pMyDoc` , para um ponteiro para `CDocument` usar essa expressão:

[!code-cpp[NVC_MFCDocView#197](../../mfc/codesnippet/cpp/type-casting-of-mfc-class-objects_1.cpp)]

Se `pMyDoc` o não apontar para um objeto derivado diretamente ou indiretamente do `CDocument` , a macro será declarada.

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
