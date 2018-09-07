---
title: Referência rápida (C++ c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: ba457195-26e5-43aa-b99d-24a871e550f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5b3ee46b2be08992fa3254edfbf2423b80dcabb1
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44102105"
---
# <a name="quick-reference-ccx"></a>Referência rápida (C++/CX)

O tempo de execução do Windows dá suporte a aplicativos de plataforma Universal do Windows (UWP) que executam apenas em um ambiente de sistema operacional confiável, usam funções autorizadas, tipos de dados e dispositivos e são distribuídos por meio do Microsoft Store. O C + + c++ /CLI CX simplificam a escrita de aplicativos para o tempo de execução do Windows. Este artigo é uma referência rápida; Para obter a documentação mais completa, consulte [sistema de tipo](../cppcx/type-system-c-cx.md).

Quando você compila na linha de comando, use o **/ZW** opção do compilador para compilar um aplicativo UWP ou um componente de tempo de execução do Windows. Para acessar as declarações de tempo de execução do Windows, que são definidas nos arquivos de metadados (. winmd) de tempo de execução do Windows, especifique a `#using` diretiva ou o **/FU** opção de compilador. Quando você cria um projeto para um aplicativo UWP, o Visual Studio por padrão define essas opções e adiciona as referências a todas as bibliotecas de tempo de execução do Windows.

## <a name="quick-reference"></a>Referência rápida

|Conceito|C++ Padrão|C++/CX|Comentários|
|-------------|--------------------|------------------------------------------------------------------|-------------|
|Tipos fundamentais|Tipos fundamentais do C++.|C + + c++ /CLI tipos fundamentais do CX que implementam tipos fundamentais que são definidos em tempo de execução do Windows.|O `default` namespace contém C + + c++ /CLI tipos fundamentais internos CX. O compilador mapeia implicitamente C + + c++ /CLI tipos fundamentais do CX para tipos C++ padrão.<br /><br /> O `Platform` família de namespaces contém tipos que implementam os tipos fundamentais do tempo de execução do Windows.|
||`bool`|`bool`|Um valor Booliano de 8 bits.|
||`__wchar_t`|`char16`|Um valor não numérico de 16 bits que representa um ponto de código Unicode (UTF-16).|
||`short`<br /><br /> `unsigned short`|`int16`<br /><br /> `uint16`|Um inteiro de 16 bits com sinal.<br /><br /> Um inteiro de 16 bits sem sinal.|
||`int`<br /><br /> `unsigned int`|`int`<br /><br /> `uint32`|Um inteiro com sinal de 32 bits.<br /><br /> Um inteiro sem sinal de 32 bits.|
||`long long` - ou - `__int64`<br /><br /> `unsigned long long`|`int64`<br /><br /> `uint64`|Um inteiro com sinal de 64 bits.<br /><br /> Um inteiro sem sinal de 64 bits.|
||`float, double`|`float32, float64`|Um número de ponto flutuante IEEE 754 de 32 ou 64 bits.|
||`enum {}`|`enum class {}`<br /><br /> -ou-<br /><br /> `enum struct {}`|Uma enumeração de 32 bits.|
||(Não se aplica)|`Platform::Guid`|Um valor não numérico de 128 bits (uma GUID) no namespace `Platform` .|
||`std::time_get`|`Windows::Foundation::DateTime`|Uma estrutura date-time.|
||(Não se aplica)|`Windows::Foundation::TimeSpan`|Uma estrutura timespan.|
||(Não se aplica)|`Platform::Object^`|O objeto base contado por referência na exibição C++ do sistema de tipo de tempo de execução do Windows.|
||`std::wstring`<br /><br /> `L"..."`|`Platform::String^`|`Platform::String^` é uma sequência de caracteres Unicode imutável, contada por referência, que representa texto.|
|Ponteiro|Ponteiro para objeto (`*`):<br /><br /> `std::shared_ptr`|Handle-to-object (`^`ou "hat"):<br /><br /> *T^ identifier*|Todas as classes de tempo de execução do Windows são declaradas usando o modificador handle-to-object. Os membros do objeto são acessados usando o operador de acesso ao membro da classe (`->`) de seta.<br /><br /> O modificador hat significa "ponteiro para um objeto de tempo de execução do Windows é automaticamente referência counted". Mais precisamente, handle-to-object declara que o compilador deve inserir código para gerenciar automaticamente a contagem de referência de objeto e excluirá o objeto se a contagem de referência chegar a zero.|
|Referência|Referência para um objeto (`&`):<br /><br /> *T* `&` *identifier*|Referência de rastreamento (`%`):<br /><br /> *T* `%` *identifier*|Modificador de referência único tempo de execução do Windows tipos podem ser declarados usando o controle. Os membros do objeto são acessados usando o operador de acesso ao membro da classe (`.`) de ponto.<br /><br /> A referência de rastreamento significa "uma referência a um objeto de tempo de execução do Windows que é automaticamente a contagem de referência". Mais precisamente, uma referência de rastreamento declara que o compilador deve inserir código para gerenciar automaticamente a contagem de referência de objeto e excluirá o objeto se a contagem de referência chegar a zero.|
|Declaração de tipo dinâmico|`new`|`ref new`|Aloca um objeto de tempo de execução do Windows e, em seguida, retorna um identificador para esse objeto.|
|gerenciamento de vida útil de objeto|`delete` *identifier*<br /><br /> `delete[]`  *identifier*|(Invoca o destruidor.)|A vida útil é determinada pela contagem de referência. Uma chamada para exclusão invoca o destruidor, mas ele próprio não libera memória.|
|declaração de matriz|*T  identifier* `[]`<br /><br /> `std::array` *identifier*|`Array<` *T* `^>^` *identifier* `(` *size* `)`<br /><br /> -ou-<br /><br /> `WriteOnlyArray<` *T* `^>`  *identifier* `(` *size* `)`|Declara uma matriz unidimensional modificável ou somente gravação do tipo T^. A própria matriz também é um objeto contado por referência que deve ser declarada usando o modificador handle-to-object.<br /><br /> (As declarações de matriz usam uma classe de cabeçalho de modelo que está no namespace `Platform` )|
|declaração de classe|`class`  *identifier* `{}`<br /><br /> `struct` *identifier* `{}`|`ref class` *identifier* `{}`<br /><br /> `ref struct` *identifier* `{}`|Declara uma classe de tempo de execução que tem acessibilidade privada padrão.<br /><br /> Declara uma classe de tempo de execução que tem acessibilidade pública padrão.|
|declaração de estrutura|`struct` *identifier* `{}`<br /><br /> (isto é, uma estrutura POD (Plain Old Data))|`value class` *identifier* `{}`<br /><br /> `value struct` *identifier* `{}`|Declara uma estrutura POD que tem acessibilidade privada padrão.<br /><br /> Uma classe de valor pode ser representada nos metadados do Windows, mas uma classe padrão do C++ padrão não pode.<br /><br /> Declara uma estrutura POD que tem acessibilidade pública padrão.<br /><br /> Uma estrutura de valor pode ser representada nos metadados do Windows, mas uma estrutura padrão C++ não pode.|
|declaração de interface|classe abstrata que contém apenas funções virtuais puras.|`interface class` *identifier* `{}`<br /><br /> `interface struct` *identifier* `{}`|Declara uma interface que tem acessibilidade privada padrão.<br /><br /> Declara uma interface que tem acessibilidade pública padrão.|
|delegado|`std::function`|`public delegate` *return-type* *delegate-type-identifier* `(` *[parâmetros]* `);`|Declara um objeto que pode ser chamado como uma chamada de função.|
|evento|(Não se aplica)|`event` *delegate-type-identifier* *event-identifier* `;`<br /><br /> *delegate-type-identifier* *delegate-identifier* = `ref new`*delegate-type-identifier*`( this`*[, parameters]*`);`<br /><br /> *event-identifier* `+=` *delegate-identifier* `;`<br /><br /> -ou-<br /><br /> `EventRegistrationToken` *token-identifier* = *obj*`.`*event-identifier*`+=`*delegate-identifier*`;`<br /><br /> -ou-<br /><br /> `auto` *token-identifier* = *obj*. *identificador de evento*`::add(`*identificador de delegado*`);`<br /><br /> *obj* `.` *event-identifier* `-=` *token-identifier* `;`<br /><br /> -ou-<br /><br /> *obj* `.` *event-identifier* `::remove(` *token-identifier* `);`|Declara um objeto de evento, que armazena uma coleção de manipuladores de eventos (delegados) que são chamados quando ocorre um evento.<br /><br /> Cria um manipulador de eventos.<br /><br /> Adiciona um manipulador de eventos.<br /><br /> A adição de um manipulador de eventos retorna um token de evento (*token-identifier*). Se você pretende remover explicitamente o manipulador de eventos, deverá salvar o token de evento para uso posterior.<br /><br /> Remove um manipulador de eventos.<br /><br /> Para remover um manipulador de eventos, você deve especificar o token de evento salvo quando o manipulador de eventos foi adicionado.|
|propriedade|(Não se aplica)|`property` *T* *identifier*;<br /><br /> `property` *T* *identifier* `[` *índice* `];`<br /><br /> `property` *T* `default[` *índice* `];`|Declara que uma função de membro de classe ou objeto é acessada usando a mesma sintaxe usada para acessar um membro de dados ou elemento de matriz indexada.<br /><br /> Declara uma propriedade em uma função de membro de classe ou objeto.<br /><br /> Declara uma propriedade indexada em uma função de membro de objeto.<br /><br /> Declara uma propriedade indexada em uma função de membro de classe.|
|Tipos parametrizados|modelos|`generic <typename` *T* `> interface class` *identifier* `{}`<br /><br /> `generic <typename` *T* `> delegate` *[tipo de retorno]* *delegate-identifier* `() {}`|Declara uma classe com de interface parametrizada.<br /><br /> Declara um delegado parametrizado.|
|Tipos de valor anuláveis|`boost::optional<T>`|[Platform:: ibox \<T >](../cppcx/platform-ibox-interface.md)|Permite que variáveis de tipos escalares e de estruturas de valor tenham um valor de `nullptr`.|

## <a name="see-also"></a>Consulte também

[Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)