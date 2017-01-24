---
title: "Localidades e p&#225;ginas de c&#243;digo | Microsoft Docs"
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
  - "conjunto de caracteres [C++], páginas de código"
  - "conjunto de caracteres [C++], localidades"
  - "páginas de código [C++]"
  - "páginas de código [C++], alterando dinamicamente"
  - "páginas de código [C++], localidades"
  - "convenções [C++], suporte a caracteres internacionais"
  - "IDs de localidade [C++]"
  - "localidades [C++]"
  - "localidades [C++], sobre localidades"
  - "localização [C++], páginas de código"
  - "localização [C++], localidades"
  - "páginas de código multibyte [C++]"
ms.assetid: bd937361-b6d3-4c98-af95-beb7c903187b
caps.latest.revision: 9
caps.handback.revision: 9
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Localidades e p&#225;ginas de c&#243;digo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma ID de localidade reflete as convenções locais e o idioma para uma região geográfica específico.  Pode ser um determinado idioma falado em mais de um país\/região; por exemplo, o português é falado em Brasil assim como em Portugal.  Por outro lado, um país\/região pode ter mais de um idioma oficial.  Por exemplo, Canadá tem dois idiomas: Inglês e francês.  Assim, Canadá tem duas localidades diferentes: Canadense\-inglês e Canadense\-francês.  Algumas categorias de localidade dependentes incluem a formatação de datas e o formato de exibição de valores monetários.  
  
 O idioma do determina as convenções de formatação de texto e de dados, quando o país\/região determinar as convenções locais.  Cada idioma tem um mapeamento exclusivo, representado por páginas de código, que inclui caracteres diferentes de aqueles no alfabeto \(como marcas e números de pontuação\).  Uma página de código é um conjunto de caracteres e está relacionado ao idioma.  Como tal, [localidade](../c-runtime-library/locale.md) é uma combinação exclusiva de idioma, de país\/região, e de página de código.  A localidade e a composição do código podem ser alteradas em tempo de execução chamando a função de [setlocale](../Topic/setlocale,%20_wsetlocale.md) .  
  
 Os idiomas diferentes podem usar páginas de código diferentes.  Por exemplo, a página de código 1252 ANSI é usada para inglês e a maioria dos idiomas europeus, e a página de código 932 ANSI é usada para o Kanji japonês.  A inclusão de todas as páginas de código diferentes compartilharem o conjunto de caracteres ASCII para o menor 128 caracteres \(0x00 a 0x7F\).  
  
 Qualquer página de código de um byte pode ser representada em uma tabela com entradas \(256\) como um mapeamento de valores de byte para caracteres \(incluindo números e marcas de pontuação\), ou em glifos.  Qualquer página de código de multibyte também pode ser representada como uma tabela muito grande \(com entradas uniforme\) de valores de byte duplo em caracteres.  Na prática, porém, normalmente é representada como uma tabela para os primeiros 256 caracteres de byte único \(\) e como intervalos para os valores de byte duplo.  
  
 Para obter mais informações sobre códigos de página, consulte [Páginas de código](../c-runtime-library/code-pages.md).  
  
 A biblioteca de tempo de execução C tem dois tipos de páginas de código internas: localidade e multibyte.  Você pode alterar a página de código atual durante a execução do programa \(consulte a documentação das funções de [setlocale](../Topic/setlocale,%20_wsetlocale.md) e de [\_setmbcp](../c-runtime-library/reference/setmbcp.md) \).  Além disso, a biblioteca de tempo de execução pode obter e usar o valor da página de código do sistema operacional.  No Windows 2000, a página de código do sistema operacional é “a página de código ANSI da opção sistema”.  Esta página de código é constante durante a execução do programa.  
  
 Quando a página de código da localidade muda, o comportamento de localidade dependente definido de alterações de funções que ditou pela página de código escolhida.  Por padrão, todas as funções de localidade dependente inicia a execução com uma página de código da localidade exclusivo da localidade de C “2.0”.  Você pode alterar a página de código interna de localidade \(assim como outras propriedades específicas de localidade\) chamando a função de `setlocale` .  Uma chamada para `setlocale`\(LC\_ALL, ""\) define a localidade que indicada pela localidade do usuário do sistema operacional.  
  
 Da mesma forma, quando a página de código de multibyte muda, o comportamento das alterações de funções multibyte a ditou pela página de código escolhida.  Por padrão, todas as funções de multibyte inicia a execução com uma página de código de multibyte que corresponde à página de código padrão do sistema operacional.  Você pode alterar a página de código multibyte interna chamando a função de `_setmbcp` .  
  
 A função `setlocale` de tempo de execução c define 2.0, modificar, ou consulta algumas ou todas as informações de localidade de programa atual.  A rotina de [\_wsetlocale](../Topic/setlocale,%20_wsetlocale.md) é uma versão de ampla caractere de `setlocale`; os argumentos e os valores de retorno de `_wsetlocale` são cadeias de caracteres de ampla caractere.  
  
## Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Benefícios da portabilidade do conjunto de caracteres](../text/benefits-of-character-set-portability.md)