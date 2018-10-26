---
title: Recursos de registro Exibir Classes (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- record views, classes
- record view classes
ms.assetid: e7b2820f-09c4-483f-83c0-317e8be42bdf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 524fd0ac48c0f26f8621c074f5460e55d7690761
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50074651"
---
# <a name="features-of-record-view-classes--mfc-data-access"></a>Recursos de classes de exibição de registro (Acesso a dados MFC)

Você pode fazer programação de acesso a dados baseado em formulário com classe [CFormView](../mfc/reference/cformview-class.md), mas [CRecordView](../mfc/reference/crecordview-class.md) geralmente é uma classe melhor derivar. Além seus `CFormView` recursos, `CRecordView`:

- Fornece a troca de dados de caixa de diálogo (DDX) entre os controles de formulário e o objeto de conjunto de registros associado.

- Lida com os comandos mover primeiro, mover próximo, mover anterior e mover último para navegar pelos registros no objeto de conjunto de registros associado.

- Atualiza as alterações feitas no registro atual quando o usuário move para outro registro.

Para obter mais informações sobre navegação, consulte [exibições de registro: suportando navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md).

## <a name="see-also"></a>Consulte também

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)