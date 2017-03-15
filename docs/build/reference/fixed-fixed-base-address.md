---
title: "/FIXED (endere&#231;o b&#225;sico fixo) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/fixed"
  - "VC.Project.VCLinkerTool.FixedBaseAddress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /FIXED"
  - "opção de vinculador FIXED"
  - "opção de vinculador -FIXED"
  - "endereço básico preferencial para carregar programa"
ms.assetid: 929bba5e-b7d8-40ed-943e-056aa3710fc5
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /FIXED (endere&#231;o b&#225;sico fixo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/FIXED[:NO]  
```  
  
## Comentários  
 Diz ao sistema operacional para carregar o programa somente em seu endereço básico preferencial.  Se o endereço básico preferido não estiver disponível, o sistema operacional não carregará o arquivo.  Para obter mais informações, consulte [\/BASE \(endereço básico\)](../../build/reference/base-base-address.md).  
  
 \/FIXED:NO é a configuração padrão para uma DLL e \/FIXED é a configuração padrão para qualquer outro tipo de projeto.  
  
 Quando \/FIXO é especificado, o link não pode gerar uma seção de realocação no programa.  No tempo de execução, se o sistema operacional não for capaz de carregar o programa no endereço especificado, ele emite uma mensagem de erro e não carrega o programa.  
  
 Especifica \/FIXED:NO para gerar uma seção de realocação no programa.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta do **Vinculador**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Digite o nome da opção e a configuração na caixa **Opções Adicionais**.  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)