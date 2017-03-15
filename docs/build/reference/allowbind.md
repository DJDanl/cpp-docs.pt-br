---
title: "/ALLOWBIND | Microsoft Docs"
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
  - "/allowbind"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "opção editbin ALLOWBIND"
  - "Opção /ALLOWBIND (editbin)"
  - "opção editbin -ALLOWBIND"
ms.assetid: eaadbb8c-4339-4281-9a75-3a1ce2352ff8
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ALLOWBIND
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica se uma DLL pode ser associado.  
  
```  
  
/ALLOWBIND[:NO]  
  
```  
  
## Comentários  
 As opções definidas de **\/ALLOWBIND** um bit no cabeçalho de uma DLL que indica a Bind.exe que a imagem é permitida ser associada.  A associação pode permitir que uma imagem carrega mais rápido quando o carregador não tem que rebase e executar o fixup de endereço para cada DLL referenciado.  Você não queira uma DLL a ser associado se foi digitalmente assinar\- associação invalida a assinatura.  Associar não tem nenhum efeito se o randomization \(ASLR\) do layout do espaço de endereço é habilitado para a imagem usando **\/DYNAMICBASE** em versões do windows que dão suporte a ASLR.  
  
 Use **\/ALLOWBIND:NO** para impedir que Bind.exe associa a DLL.  
  
 Para obter mais informações, consulte a opção do vinculador de [\/ALLOWBIND](../../build/reference/allowbind-prevent-dll-binding.md) .  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)