---
title: "Diretivas de modelo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "diretiva de modelo [!else]"
  - "diretiva de modelo [!endif]"
  - "diretiva de modelo [!endloop]"
  - "diretiva de modelo [!if]"
  - "diretiva de modelo [!loop]"
  - "diretiva de modelo [!output]"
  - "assistentes personalizados, diretivas de modelo"
  - "Diretivas (), diretivas de modelo"
  - "diretiva else ([!else])"
  - "diretiva endif ([!endif])"
  - "diretiva endloop ([!endloop])"
  - "diretiva if ([!if])"
  - "diretiva loop ([!loop])"
  - "diretiva output ([!output])"
  - "diretivas de modelo"
ms.assetid: b6204153-813a-423c-b044-e39c352cc5af
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Diretivas de modelo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar as seguintes diretivas de modelo em um assistente  [arquivo de modelo](../ide/template-files.md) e o  [o arquivo de Templates.inf](../Topic/Templates.inf%20File.md) para personalizar o assistente.  
  
|Diretiva|Descrição|  
|--------------|---------------|  
|\[\!  IF\]|Começa uma estrutura de controle para verificar se há uma condição.|  
|\[\!  else\]|Parte do \[\!  IF\] controlam estrutura.  Outra condição de procura.|  
|\[\!  endif\]|Finaliza a definição de um \[\!  IF\] controlam estrutura.|  
|\[\!  saída\]|Pode ser usado de duas maneiras a seguir:<br /><br /> -   \[\!  saída "string"\] lhe dá a seqüência de caracteres.<br />-   \[\!  SYMBOL\_STRING de saída\] fornece o valor do símbolo SYMBOL\_STRING.|  
|\[\!  loop\]|Pode ser usado de duas maneiras a seguir:<br /><br /> -   \[\!  loop \= 5\]<br />-   \[\!  loop \=  *NUM\_OF\_PAGES* \] onde  *NUM\_OF\_PAGES* é um símbolo com um valor numérico.|  
|\[\!  ENDLOOP\]|Termina uma estrutura de loop.|  
  
 O colchete esquerdo \(\[\]\) seguido imediatamente por um ponto de exclamação \(\!\) indica o início de uma diretiva de modelo.  O colchete direito indica o fim de uma diretiva de modelo.  Esta é a sintaxe necessária:  
  
```  
[!directive params]  
```  
  
 É necessário apenas entre um espaço ou um caractere não\-identifier  *diretiva*  e  *params*.  
  
## Exemplo  
  
```  
[!if SAMPLE_RADIO_OPTION1]  
You have checked the option 'Sample radio button option 1'  
[!else]  
You have checked the option 'Sample radio button option 2'  
[!endif]  
```  
  
 Você pode usar os seguintes operadores com as diretivas acima em um arquivo de modelo.  
  
```  
+  
-     
=  
!=     
==     
||     
&&    
!  
```  
  
## Exemplo  
  
```  
[!if SYMBOL_STRING != 0]  
```  
  
## Consulte também  
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)