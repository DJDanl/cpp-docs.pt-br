---
title: Trabalhando com documentos e exibições | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], documents
- MFC [C++], views
- views [C++], MFC
- documents [C++], MFC
ms.assetid: 349b142d-1c5a-4b99-9de4-241e41d3d2f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c3879c6a29f95cc908d12c0b899214b521f46686
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060437"
---
# <a name="working-with-documents-and-views"></a>Trabalhando com documentos e exibições

A biblioteca Microsoft Foundation Classes (MFC) se baseia em uma arquitetura de documento/exibição para muitos de seus recursos. Normalmente, um documento armazena seus dados e um modo de exibição exibe-o dentro da área de cliente de uma janela de quadro e gerencia a interação do usuário com os dados. O modo de exibição se comunica com o documento para obter e atualizar os dados. Você pode usar as classes de banco de dados com a estrutura ou sem ele.

Para obter mais informações sobre como usar classes de banco de dados na estrutura, consulte [MFC: usando Classes de banco de dados com documentos e exibições](../../data/mfc-using-database-classes-with-documents-and-views.md).

Por padrão, o Assistente de aplicativo MFC cria um aplicativo de esqueleto sem suporte de banco de dados. No entanto, você pode selecionar opções para incluir suporte mínimo de banco de dados ou o mais completo suporte baseado em formulário. Para obter mais informações sobre as opções do Assistente de aplicativo, consulte [suporte de banco de dados, o Assistente de aplicativo MFC](../../mfc/reference/database-support-mfc-application-wizard.md).

Você também pode usar as classes de banco de dados sem usar a arquitetura de documento/exibição completa. Para obter mais informações, consulte [MFC: usando Classes de banco de dados sem documentos e exibições](../../data/mfc-using-database-classes-without-documents-and-views.md).

## <a name="see-also"></a>Consulte também

[ODBC e MFC](../../data/odbc/odbc-and-mfc.md)