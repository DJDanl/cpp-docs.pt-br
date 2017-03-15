---
title: "Vari&#225;veis de ambiente CL | Microsoft Docs"
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
  - "cl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, variáveis de ambiente"
  - "variáveis de ambiente, compilador CL"
  - "variável de ambiente INCLUDE"
  - "variável de ambiente LIBPATH"
ms.assetid: 2606585b-a681-42ee-986e-1c9a2da32108
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vari&#225;veis de ambiente CL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A ferramenta CL usa as seguintes variáveis de ambiente:  
  
-   CL e \_CL\_, se definido.  A ferramenta CL precede as opções e argumentos definidos na variável de ambiente CL para os argumentos de linha de comando e acrescenta as opções e argumentos definidos no \_CL\_ antes do processamento.  
  
-   INCLUA, que deve apontar para o subdiretório \\include da instalação do Visual C\+\+.  
  
-   LIBPATH, que especifica os diretórios para procurar arquivos de metadados referenciados com [\#using](../../preprocessor/hash-using-directive-cpp.md).  Consulte `#using` para obter mais informações sobre LIBPATH.  
  
 Você pode definir a variável de ambiente CL ou \_CL\_ usando a seguinte sintaxe:  
  
```  
SET CL=[ [option] ... [file] ...] [/link link-opt ...]  
SET _CL_=[ [option] ... [file] ...] [/link link-opt ...]  
```  
  
 Para obter detalhes sobre os argumentos para as variáveis de ambiente CL e \_CL\_, consulte [sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md).  
  
 Você pode usar essas variáveis de ambiente para definir as opções usadas com mais freqüência e arquivos e usar a linha de comando para definir opções e arquivos específicos para fins específicos.  As variáveis de ambiente CL e \_CL\_ estão limitadas a 1024 caracteres \(o limite de entrada de linha de comando\).  
  
 Você não pode usar a opção \/d. para definir um símbolo que usa um sinal de igual \(\=\).  Você pode substituir o sinal numérico \(\#\) para um sinal de igual.  Dessa forma, você pode usar as variáveis CL ou \_CL\_environment para definir constantes pré\-processador com valores explícitos — por exemplo, `1 DDEBUG` para definir `DEBUG=1`.  
  
 Para obter informações relacionadas, consulte [definir variáveis de ambiente](../../build/setting-the-path-and-environment-variables-for-command-line-builds.md).  
  
## Exemplos  
 Este é um exemplo da variável de ambiente CL definição:  
  
```  
SET CL=/Zp2 /Ox /I\INCLUDE\MYINCLS \LIB\BINMODE.OBJ  
```  
  
 Quando essa variável de ambiente é definida, se você digitar `entrada CL. C` na linha de comando, isso é o comando eficaz:  
  
```  
CL /Zp2 /Ox /I\INCLUDE\MYINCLS \LIB\BINMODE.OBJ INPUT.C  
```  
  
 O exemplo a seguir faz com que um simples comando CL compilar os arquivos de origem File1 e File2. c e, em seguida, vincular os arquivos de objeto FILE1.obj, FILE2.obj e FILE3.obj:  
  
```  
SET CL=FILE1.C FILE2.C  
SET _CL_=FILE3.OBJ  
CL  
  
```  
  
 Isso tem o mesmo efeito que a seguinte linha de comando:  
  
```  
CL FILE1.C FILE2.C FILE3.OBJ  
```  
  
## Consulte também  
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)