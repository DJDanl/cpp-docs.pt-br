---
title: "Como: alterar o idioma ou a condição de um recurso ao copiar | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.resvw.resource.changing
dev_langs: C++
helpviewer_keywords:
- Language property
- condition property of resource
ms.assetid: 8f622ab0-bac2-468f-ae70-78911afc4759
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3655366e8851494482e628b9c260c796df3f64bd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-change-the-language-or-condition-of-a-resource-while-copying"></a>Como alterar a linguagem ou a condição de um recurso durante a cópia
Durante a cópia em um recurso, você pode alterar a propriedade de idioma ou propriedade de condição ou ambos.  
  
-   O idioma do recurso identifica exatamente isso, o idioma do recurso. Isso é usado por [FindResource](http://msdn.microsoft.com/library/windows/desktop/ms648042) para ajudar a identificar o recurso para o qual você está procurando. (No entanto, recursos podem ter diferenças para cada idioma que não estão relacionados a texto, por exemplo, compilações Aceleradores podem funcionar apenas em um teclado japonês ou um bitmap que só podem ser adequado para chinês localizadas, etc.)  
  
-   A condição de um recurso é um símbolo definido que identifica uma condição sob a qual essa cópia particular do recurso é usado.  
  
 O idioma e a condição de um recurso são mostrados entre parênteses após o nome do recurso na janela do espaço de trabalho. Neste exemplo o recurso denominado IDD_AboutBox e estiver usando finlandês como sua linguagem de sua condição XX33.  
  
```  
IDD_AboutBox (Finnish - XX33)  
```  
  
### <a name="to-copy-an-existing-resource-and-change-its-language-or-condition"></a>Para copiar um recurso existente e alterar o idioma ou condição  
  
1.  O arquivo. rc ou no [exibição recursos](../windows/resource-view-window.md) janela, clique o recurso que você deseja copiar.  
  
2.  Escolha **inserir cópia** no menu de atalho.  
  
3.  No **inserir cópia do recurso** caixa de diálogo:  
  
    -   Para o **idioma** caixa de listagem, selecione o idioma.  
  
    -   No **condição** , digite a condição.  
  

  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Como: copiar recursos](../windows/how-to-copy-resources.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)