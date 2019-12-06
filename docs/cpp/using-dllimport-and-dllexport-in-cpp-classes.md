---
title: Usando o dllimport e o dllexport nas classes do C++
ms.date: 11/04/2016
helpviewer_keywords:
- exporting classes [C++]
- declarations [C++], class
- exportable classes [C++]
- classes [C++], declaring
- classes [C++], exportable and inheritance
- inheritance [C++], exportable classes [C++]
- dllimport attribute [C++], classes
- declaring classes [C++]
- dllexport attribute [C++]
- dllexport attribute [C++], classes [C++]
ms.assetid: 8d7d1303-b9e9-47ca-96cc-67bf444a08a9
ms.openlocfilehash: b42ba7c1a88a4de28eb3385bbf6cad068abf1944
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857223"
---
# <a name="using-dllimport-and-dllexport-in-c-classes"></a>Usando o dllimport e o dllexport nas classes do C++

**Seção específica da Microsoft**

Você pode declarar C++ classes com o atributo **DllImport** ou **dllexport** . Esses formulários implicam que a classe inteira será importada ou exportada. As classes exportadas dessa maneira são chamadas classes exportáveis.

O exemplo a seguir define uma classe exportável. Todas as suas funções de membro e dados estáticos são exportados:

```cpp
#define DllExport   __declspec( dllexport )

class DllExport C {
   int i;
   virtual int func( void ) { return 1; }
};
```

Observe que o uso explícito dos atributos **DllImport** e **dllexport** nos membros de uma classe exportável é proibido.

##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2bdllexportclasses"></a>Classes dllexport

Quando você declara uma classe **dllexport**, todas as suas funções de membro e membros de dados estáticos são exportados. Você deve fornecer as definições de todos esses membros no mesmo programa. Caso contrário, será gerado um erro de vinculador. A única exceção a essa regra se aplica às funções virtuais puras, para as quais você não precisa fornecer definições explícitas. No entanto, como um destruidor de uma classe abstrata é sempre chamado pelo destruidor da classe base, os destruidores virtuais puros devem fornecer sempre uma definição. Essas regras são as mesmas para classes não exportáveis.

Se você exportar dados do tipo de classe ou de funções que retornarem classes, exporte a classe.

##  <a name="_pluslang_dllexport_classesdllexportclasses"></a>Classes DllImport

Quando você declara uma classe **DllImport**, todas as suas funções de membro e membros de dados estáticos são importados. Ao contrário do comportamento de **DllImport** e **dllexport** em tipos não de classe, os membros de dados estáticos não podem especificar uma definição no mesmo programa no qual uma classe **DllImport** é definida.

##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2binheritanceandexportableclasses"></a>Classes de herança e exportáveis

Todas as classes base de uma classe exportável devem ser exportáveis. Caso contrário, um aviso do compilador será gerado. Além disso, todos os membros acessíveis que também são classes devem ser exportáveis. Essa regra permite que uma classe **dllexport** herde de uma classe **DllImport** e uma classe **DllImport** para herdar de uma classe **dllexport** (embora o último não seja recomendado). Como regra, tudo que pode ser acessado pelo cliente da DLL (de acordo com as regras de acesso do C++) deve fazer parte da interface exportável. Isso inclui os membros de dados confidenciais referenciados em funções integradas.

##  <a name="_pluslang_using_dllimport_and_dllexport_in_c2b2bselectivememberimportexport"></a>Importação/exportação de membro seletivo

Como as funções de membro e os dados estáticos em uma classe implicitamente têm vínculo externo, você pode declará-las com o atributo **DllImport** ou **dllexport** , a menos que toda a classe seja exportada. Se a classe inteira for importada ou exportada, a declaração explícita de funções e dados de membro como **DllImport** ou **dllexport** será proibida. Se você declarar um membro de dados estáticos dentro de uma definição de classe como **dllexport**, uma definição deverá ocorrer em algum lugar dentro do mesmo programa (como com vinculação externa sem classe).

Da mesma forma, você pode declarar funções de membro com os atributos **DllImport** ou **dllexport** . Nesse caso, você deve fornecer uma definição de **dllexport** em algum lugar dentro do mesmo programa.

Vale a pena observar vários pontos importantes sobre a importação e a exportação seletiva de membros:

- A importação/exportação seletiva de membros é melhor usada para o fornecimento de uma versão da interface de classe exportada mais restritiva, isto é, uma para a qual você pode criar uma DLL que exponha menos recursos públicos e particulares do que a linguagem normalmente permitiria. Também é útil para ajustar a interface exportável: quando você souber que o cliente, por definição, não pode acessar alguns dados particulares, não precisará exportar a classe inteira.

- Se você exportar uma função virtual em uma classe, deverá exportar todas elas ou pelo menos fornecer versões que poderão ser diretamente usadas pelo cliente.

- Se você tiver uma classe em que usa a importação/exportação seletiva de membros com funções virtuais, as funções deverão estar na interface exportável ou ser definidas como integradas (podem ser vistas pelo cliente).

- Se você definir um membro como **dllexport** , mas não o incluir na definição de classe, um erro do compilador será gerado. Você deve definir o membro no cabeçalho da classe.

- Embora a definição de membros de classe como **DllImport** ou **dllexport** seja permitida, você não pode substituir a interface especificada na definição de classe.

- Se você definir uma função de membro em um local diferente do corpo da definição de classe na qual você o declarou, um aviso será gerado se a função for definida como **dllexport** ou **DllImport** (se essa definição for diferente da especificada na declaração de classe).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[dllexport, dllimport](../cpp/dllexport-dllimport.md)