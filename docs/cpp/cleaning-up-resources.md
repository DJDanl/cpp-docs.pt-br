---
title: "Limpando recursos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de exceção de C++, manipuladores de encerramento"
  - "tratamento de exceção, limpando recursos"
  - "tratamento de exceção, código de limpeza"
  - "recursos [C++], limpando"
  - "manipuladores de encerramento, limpando recursos"
  - "palavra-chave try-catch [C++], manipuladores de encerramento"
ms.assetid: 65753efe-6a27-4750-b90c-50635775c1b6
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Limpando recursos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Durante a execução do manipulador de término, talvez você não saiba quais recursos foram realmente alocados antes que o manipulador de término seja chamado.  É possível que o bloco de instruções `__try` tenha sido interrompido antes que todos os recursos tenham sido alocados e, assim, nem todos os recursos tenham sido abertos.  
  
 Portanto, para garantir, você deve verificar quais recursos estão realmente abertos antes de continuar com a limpeza da manipulação de término.  Um procedimento recomendado é fazer o seguinte:  
  
1.  Inicialize os identificadores como NULL.  
  
2.  No bloco de instruções `__try`, aloque recursos.  Os identificadores são definidos como valores positivos conforme o recurso é alocado.  
  
3.  No bloco de instruções `__finally`, libere cada recurso cuja variável handle ou flag correspondente seja diferente de zero ou não NULL.  
  
## Exemplo  
 Por exemplo, o código a seguir usa um manipulador de término para fechar três arquivos e um bloco de memória que foram alocados no bloco de instruções `__try`.  Antes de limpar um recurso, o código primeiro verifica se o recurso foi alocado.  
  
```  
// exceptions_Cleaning_up_Resources.cpp  
#include <stdlib.h>  
#include <malloc.h>  
#include <stdio.h>  
#include <windows.h>  
  
void fileOps() {  
   FILE  *fp1 = NULL,  
         *fp2 = NULL,  
         *fp3 = NULL;  
   LPVOID lpvoid = NULL;  
   errno_t err;  
  
   __try {  
      lpvoid = malloc( BUFSIZ );  
  
      err = fopen_s(&fp1, "ADDRESS.DAT", "w+" );  
      err = fopen_s(&fp2, "NAMES.DAT", "w+" );  
      err = fopen_s(&fp3, "CARS.DAT", "w+" );  
   }  
   __finally {  
      if ( fp1 )  
         fclose( fp1 );  
      if ( fp2 )  
         fclose( fp2 );  
      if ( fp3 )  
         fclose( fp3 );  
      if ( lpvoid )  
         free( lpvoid );  
   }  
}  
  
int main() {  
   fileOps();  
}  
```  
  
## Consulte também  
 [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)   
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)