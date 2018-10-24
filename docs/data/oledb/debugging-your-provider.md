---
title: Depurando o provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- debugging [C++], providers
- OLE DB providers, debugging
- Visual C++ debugger, debugging providers
- Visual C++ debugger
ms.assetid: 90d4e7db-06ea-4de0-a7f4-4f3751d50d93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: fc4461bb29bb9b9c706177c4dcd2134d37d697e0
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49989899"
---
# <a name="debugging-your-provider"></a>Depurando o provedor

Há duas maneiras para depurar seu provedor:  
  
- Como provedores são criados no processo, você pode criar um código de consumidor usando os modelos de consumidor OLE DB e a etapa no provedor de normalmente.  
  
- Você pode usar o utilitário ITEST que vem com o Visual C++.  
  
## <a name="to-use-the-itest-utility"></a>Usar o utilitário ITEST  
  
1. Abra o projeto de provedor.  
  
1. Sobre o **projetos** menu, clique em **configurações**.  
  
1. No **páginas de propriedades** caixa de diálogo, clique o **depurar** guia.  
  
1. No **Executable for Debug Session** , selecione o aplicativo ITEST.  
  
1. Definir pontos de interrupção e, em seguida, depure como de costume.  
  
## <a name="see-also"></a>Consulte também  

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)