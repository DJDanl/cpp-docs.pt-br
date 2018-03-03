---
title: "Adicionando formatação ou caracteres especiais em uma cadeia de caracteres | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- special characters, adding to strings
- ASCII characters, adding to strings
- strings [C++], formatting
- strings [C++], special characters
ms.assetid: c40f394a-8b2c-4896-ab30-6922863ddbb5
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ca91ef9742f2dfb10a0af12c74ca58f80035d131
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-formatting-or-special-characters-to-a-string"></a>Adicionando formatação ou caracteres especiais a uma cadeia de caracteres
### <a name="to-add-formatting-or-special-characters-to-a-string"></a>Para adicionar formatação ou caracteres especiais em uma cadeia de caracteres  
  
1.  Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição recursos](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Selecione a cadeia de caracteres que você deseja modificar.  
  
3.  No [janela propriedades](/visualstudio/ide/reference/properties-window), adicionar qualquer uma das sequências de escape padrão listados abaixo para o texto a **legenda** caixa e pressione **ENTER**.  
  
    |Para começar|Digite isto|  
    |-----------------|---------------|  
    |Nova linha|\n|  
    |Retorno de carro|\r|  
    |Tabulação|\t|  
    |Barra invertida (\\)|\\\|  
    |Caracteres ASCII|\ddd (notação octal)|  
    |alerta (sino)|\a|  
  
> [!NOTE]
>  O editor de cadeia de caracteres não oferece suporte a todo o conjunto de caracteres de escape ASCI. Você pode usar somente aqueles listados acima.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que se destinam a common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/en-us/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de cadeias de caracteres](../windows/string-editor.md)   

