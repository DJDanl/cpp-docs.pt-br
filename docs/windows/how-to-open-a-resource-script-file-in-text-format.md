---
title: 'Como: abrir um arquivo de Script de recurso no formato de texto | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.resource
dev_langs:
- C++
helpviewer_keywords:
- resource script files, opening in text format
- .rc files, opening in text format
- rc files, opening in text format
ms.assetid: 0bc57527-f53b-40c9-99a9-4dcbc5c9af57
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 14af857d7727ee8df13a9eb6c438342007252950
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="how-to-open-a-resource-script-file-in-text-format"></a>Como abrir o arquivo de script do recurso no formato de texto
Pode haver momentos quando você deseja exibir o conteúdo do arquivo de script (. rc) do recurso do projeto sem abrir um recurso, como uma caixa de diálogo dentro do editor de recurso específico. Por exemplo, convém procurar uma cadeia de caracteres em todas as caixas de diálogo no arquivo de recurso sem precisar abrir cada um separadamente.  
  
> [!NOTE]
>  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
 Você pode facilmente abrir o arquivo de recurso no formato de texto para exibir todos os recursos que ele contém e executar operações globais com suporte a [editor de texto](http://msdn.microsoft.com/en-us/508e1f18-99d5-48ad-b5ad-d011b21c6ab1).  
  
> [!NOTE]
>  Os editores de recursos não leia arquivos. rc ou resource.h diretamente. O compilador de recurso compila em arquivos de .aps, que são consumidos por editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como o processo de compilação com um normal, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps fica fora de sincronia com o arquivo. RC, o arquivo. RC é gerada novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o arquivo resource.h). As alterações aos recursos próprios permanecerá incorporadas no arquivo. RC, mas comentários sempre será perdidos quando o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).  
  
### <a name="to-open-a-resource-script-file-as-text"></a>Para abrir um arquivo de script de recurso como texto  
  
1.  Do **arquivo** menu escolha **abrir**, em seguida, clique em **arquivo.**  
  
2.  No **abrir arquivo** caixa de diálogo, navegue até o arquivo de script de recurso que você deseja exibir no formato de texto.  
  
3.  Realce o arquivo e, em seguida, clique na seta suspensa no **abrir** botão (localizado à direita do botão).  
  
4.  Escolha **abrir com** no menu suspenso.  
  
5.  No **abrir com** caixa de diálogo, clique em **Editor de código-fonte (texto)**.  
  
6.  Do **abrir como** lista suspensa, selecione **texto**.  
  
     O recurso é aberto no editor de código-fonte.  
  
 \- ou -  
  
1.  Em **Solution Explorer**, com o botão direito no arquivo. rc.  
  
2.  No menu de atalho, escolha **abrir com...** , em seguida, selecione **Editor de código-fonte (texto)**.  
  

  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)