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
ms.openlocfilehash: 953acc32c3510b31c265f2d64d0a013f6dee06cc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372890"
---
# <a name="type-casting-of-mfc-class-objects"></a>Conversão de tipo de objetos de classe MFC

As macros de fundição de tipo fornecem uma maneira de lançar um determinado ponteiro para um ponteiro que aponta para um objeto de classe específica, com ou sem verificar se o elenco é legal.

A tabela a seguir lista as macros de fundição do tipo MFC.

### <a name="macros-that-cast-pointers-to-mfc-class-objects"></a>Macros que lançam ponteiros para objetos de classe MFC

|||
|-|-|
|[DYNAMIC_DOWNCAST](#dynamic_downcast)|Lança um ponteiro para um ponteiro para um objeto de classe enquanto verifica se o elenco é legal.|
|[STATIC_DOWNCAST](#static_downcast)|Lança um ponteiro para um objeto de uma classe para um ponteiro de um tipo relacionado. Em uma compilação de depuração, causa um ASSERT se o objeto não for um "tipo" do tipo de destino.|

## <a name="dynamic_downcast"></a><a name="dynamic_downcast"></a>DYNAMIC_DOWNCAST

Fornece uma maneira útil de lançar um ponteiro para um ponteiro para um objeto de classe enquanto verifica se o elenco é legal.

```
DYNAMIC_DOWNCAST(class, pointer)
```

### <a name="parameters"></a>Parâmetros

*classe*<br/>
O nome de uma classe.

*ponteiro*<br/>
Um ponteiro a ser lançado a um ponteiro para um objeto de *classe*tipo .

### <a name="remarks"></a>Comentários

A macro lançará o parâmetro *do ponteiro* para um ponteiro para um objeto do tipo do parâmetro de *classe.*

Se o objeto referenciado pelo ponteiro for um "tipo de" a classe identificada, a macro reahde o ponteiro apropriado. Se não for um elenco legal, a macro retorna NULL.

## <a name="static_downcast"></a><a name="static_downcast"></a>STATIC_DOWNCAST

Lança *pobject* para um ponteiro para um objeto *class_name.*

```
STATIC_DOWNCAST(class_name, pobject)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe que está sendo lançada.

*Pobject*<br/>
O ponteiro a ser lançado para um ponteiro para um objeto *class_name.*

### <a name="remarks"></a>Comentários

*pobject* deve ser NULO ou apontar para um objeto de uma classe que é derivado direta ou indiretamente, de *class_name*. Em builds do seu aplicativo com o _DEBUG símbolo de pré-processador definido, a macro AFIRMARá se *o pobject* não for NULL ou se ele aponta para um objeto que não é um "tipo" de classe especificada no parâmetro *class_name* (ver [CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof)). Em compilações não **_DEBUG,** a macro executa o elenco sem qualquer verificação do tipo.

A classe especificada no parâmetro *class_name* deve `CObject` ser derivada e deve usar o DECLARE_DYNAMIC e IMPLEMENT_DYNAMIC, o DECLARE_DYNCREATE e IMPLEMENT_DYNCREATE, ou as macros DECLARE_SERIAL e IMPLEMENT_SERIAL conforme explicado no artigo [CObject Class: Derivando uma Classe de CObject](../../mfc/deriving-a-class-from-cobject.md).

Por exemplo, você pode `CMyDoc`lançar `pMyDoc`um ponteiro para, chamado, para um ponteiro para `CDocument` usar esta expressão:

[!code-cpp[NVC_MFCDocView#197](../../mfc/codesnippet/cpp/type-casting-of-mfc-class-objects_1.cpp)]

Se `pMyDoc` não apontar para um objeto derivado `CDocument`direta ou indiretamente de , a macro afirmará.

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
