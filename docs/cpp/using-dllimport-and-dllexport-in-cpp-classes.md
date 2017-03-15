---
title: "Usando dllimport e dllexport em classes C++ | Microsoft Docs"
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
  - "classes [C++], declarando"
  - "classes [C++], exportável e herança"
  - "declarações [C++], classe"
  - "declarando classes"
  - "atributo dllexport [C++]"
  - "atributo dllexport [C++], Classes "
  - "Atributo dllimport [C++], Classes "
  - "classes exportáveis [C++]"
  - "exportando classes"
  - "herança [C++], classes exportáveis"
ms.assetid: 8d7d1303-b9e9-47ca-96cc-67bf444a08a9
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando dllimport e dllexport em classes C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 É possível declarar classes de C\+\+ com o atributo **dllimport** ou `dllexport`.  Esses formulários implicam que a classe inteira será importada ou exportada.  As classes exportadas dessa maneira são chamadas classes exportáveis.  
  
 O exemplo a seguir define uma classe exportável.  Todas as suas funções de membro e dados estáticos são exportados:  
  
```  
#define DllExport   __declspec( dllexport )  
  
class DllExport C {  
   int i;  
   virtual int func( void ) { return 1; }  
};  
```  
  
 O uso explícito dos atributos **dllimport** e `dllexport` em membros de uma classe exportável é proibido.  
  
##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2bdllexportclasses"></a> Classes dllexport  
 Ao declarar uma classe `dllexport`, todos os seus membros de dados estáticos e funções membro são exportados.  Você deve fornecer as definições de todos esses membros no mesmo programa.  Caso contrário, será gerado um erro de vinculador.  A única exceção a essa regra se aplica às funções virtuais puras, para as quais você não precisa fornecer definições explícitas.  No entanto, como um destruidor de uma classe abstrata é sempre chamado pelo destruidor da classe base, os destruidores virtuais puros devem fornecer sempre uma definição.  Essas regras são as mesmas para classes não exportáveis.  
  
 Se você exportar dados do tipo de classe ou de funções que retornarem classes, exporte a classe.  
  
##  <a name="_pluslang_dllexport_classesdllexportclasses"></a> Classes dllimport  
 Ao declarar uma classe **dllimport**, todos os seus membros de dados estáticos e funções membro são importados.  Ao contrário do comportamento de **dllimport** e de `dllexport` em tipos sem classe, os membros de dados estáticos não podem especificar uma definição no mesmo programa em que uma classe **dllimport** é definida.  
  
##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2binheritanceandexportableclasses"></a> Herança e classes exportáveis  
 Todas as classes base de uma classe exportável devem ser exportáveis.  Caso contrário, um aviso do compilador será gerado.  Além disso, todos os membros acessíveis que também são classes devem ser exportáveis.  Essa regra permite que uma classe `dllexport` herde de uma classe **dllimport** e que uma classe **dllimport** herde de uma classe `dllexport` \(embora a última não seja recomendada\).  Como regra, tudo que pode ser acessado pelo cliente da DLL \(de acordo com as regras de acesso do C\+\+\) deve fazer parte da interface exportável.  Isso inclui os membros de dados confidenciais referenciados em funções integradas.  
  
##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2bselectivememberimportexport"></a> Importação\/exportação seletiva de membros  
 Como as funções de membro e os dados estáticos dentro de uma classe têm implicitamente vinculação externa, você pode declará\-las com o atributo **dllimport** ou `dllexport`, a menos que a classe inteira seja exportada.  Se a classe inteira for importada ou exportada, a declaração explícita das funções de membro e dados como **dllimport** ou `dllexport` será proibida.  Se você declarar um membro de dados estáticos em uma definição de classe como `dllexport`, deverá ocorrer uma definição em algum lugar no mesmo programa \(assim como ocorre na vinculação externa sem classe\).  
  
 Da mesma forma, você pode declarar funções de membro com os atributos **dllimport** ou `dllexport`.  Nesse caso, você deve fornecer uma definição de `dllexport` em algum lugar dentro do mesmo programa.  
  
 Vale a pena observar vários pontos importantes sobre a importação e a exportação seletiva de membros:  
  
-   A importação\/exportação seletiva de membros é melhor usada para o fornecimento de uma versão da interface de classe exportada mais restritiva, isto é, uma para a qual você pode criar uma DLL que exponha menos recursos públicos e particulares do que a linguagem normalmente permitiria.  Também é útil para ajustar a interface exportável: quando você souber que o cliente, por definição, não pode acessar alguns dados particulares, não precisará exportar a classe inteira.  
  
-   Se você exportar uma função virtual em uma classe, deverá exportar todas elas ou pelo menos fornecer versões que poderão ser diretamente usadas pelo cliente.  
  
-   Se você tiver uma classe em que usa a importação\/exportação seletiva de membros com funções virtuais, as funções deverão estar na interface exportável ou ser definidas como integradas \(podem ser vistas pelo cliente\).  
  
-   Se você definir um membro como `dllexport` mas não incluí\-lo na definição de classe, um erro do compilador será gerado.  Você deve definir o membro no cabeçalho da classe.  
  
-   Embora a definição de membros de classe como **dllimport** ou `dllexport` seja permitida, não é possível substituir a interface especificada na definição de classe.  
  
-   Se você definir uma função de membro em um lugar que não seja o corpo da definição de classe na qual você a declarou, um aviso será gerado se a função for definida como `dllexport` ou **dllimport** \(se essa definição for diferente da especificada na declaração da classe\).  
  
### FIM de Específico da Microsoft  
  
## Consulte também  
 [dllexport, dllimport](../cpp/dllexport-dllimport.md)